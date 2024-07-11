#include <fstream>

#include "../Back/parser.h"
#include "gtest/gtest.h"

void createTempFile(const char* filename, const char* content) {
  std::ofstream file(filename);
  file << content;
  file.close();
}

TEST(ArraysCreateTest, HandlesEmptyFile) {
  const char* filename = "empty.obj";
  createTempFile(filename, "");

  double vArray[100] = {0};
  unsigned int fArray[100] = {0};

  int result = model::arraysCreate(vArray, fArray, (char*)filename);

  EXPECT_EQ(result, 0);
  EXPECT_EQ(vArray[0], 0);
  EXPECT_EQ(fArray[0], 0);
}

TEST(ArraysCreateTest, HandlesVerticesOnly) {
  const char* filename = "vertices.obj";
  createTempFile(filename, "v 1.0 2.0 3.0\nv 4.0 5.0 6.0\n");

  double vArray[100] = {0};
  unsigned int fArray[100] = {0};

  int result = model::arraysCreate(vArray, fArray, (char*)filename);

  EXPECT_EQ(result, 0);
  EXPECT_EQ(vArray[0], 1.0);
  EXPECT_EQ(vArray[1], 2.0);
  EXPECT_EQ(vArray[2], 3.0);
  EXPECT_EQ(vArray[3], 4.0);
  EXPECT_EQ(vArray[4], 5.0);
  EXPECT_EQ(vArray[5], 6.0);
}

TEST(ArraysCreateTest, HandlesFaces) {
  const char* filename = "faces.obj";
  createTempFile(filename, "v 1.0 2.0 3.0\nv 4.0 5.0 6.0\nf 1 2\n");

  double vArray[100] = {0};
  unsigned int fArray[100] = {0};

  int result = model::arraysCreate(vArray, fArray, (char*)filename);

  EXPECT_EQ(result, 0);
  EXPECT_EQ(vArray[0], 1.0);
  EXPECT_EQ(vArray[1], 2.0);
  EXPECT_EQ(vArray[2], 3.0);
  EXPECT_EQ(vArray[3], 4.0);
  EXPECT_EQ(vArray[4], 5.0);
  EXPECT_EQ(vArray[5], 6.0);

  EXPECT_EQ(fArray[0], 0);
  EXPECT_EQ(fArray[1], 1);
}

TEST(ArraysCreateTest, HandlesFileNotFound) {
  double vArray[100] = {0};
  unsigned int fArray[100] = {0};

  int result = model::arraysCreate(vArray, fArray, (char*)"nonexistent.obj");

  EXPECT_EQ(result, 1);
}

TEST(ReaderTest, HandlesEmptyFile) {
  const char* filename = "empty.obj";
  createTempFile(filename, "");

  int vCount = 0;
  int fCount = 0;

  model::reader((char*)filename, &vCount, &fCount);

  EXPECT_EQ(vCount, 0);
  EXPECT_EQ(fCount, 0);
}

TEST(ReaderTest, HandlesVerticesOnly) {
  const char* filename = "vertices.obj";
  createTempFile(filename, "v 1.0 2.0 3.0\nv 4.0 5.0 6.0\n");

  int vCount = 0;
  int fCount = 0;

  model::reader((char*)filename, &vCount, &fCount);

  EXPECT_EQ(vCount, 6);
  EXPECT_EQ(fCount, 0);
}

TEST(ReaderTest, HandlesFacesOnly) {
  const char* filename = "faces.obj";
  createTempFile(filename, "f 1 2\nf 2 3\n");

  int vCount = 0;
  int fCount = 0;

  model::reader((char*)filename, &vCount, &fCount);

  EXPECT_EQ(vCount, 0);
  EXPECT_EQ(fCount, 4);
}

TEST(ReaderTest, HandlesMixedContent) {
  const char* filename = "mixed.obj";
  createTempFile(filename, "v 1.0 2.0 3.0\nv 4.0 5.0 6.0\nf 1 2\n");

  int vCount = 0;
  int fCount = 0;

  model::reader((char*)filename, &vCount, &fCount);

  EXPECT_EQ(vCount, 6);
  EXPECT_EQ(fCount, 2);
}

TEST(ReaderTest, HandlesFileNotFound) {
  int vCount = 0;
  int fCount = 0;

  testing::internal::CaptureStdout();
  model::reader((char*)"nonexistent.obj", &vCount, &fCount);
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(vCount, 0);
  EXPECT_EQ(fCount, 0);
  EXPECT_EQ(output, "cant open file\n");
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
