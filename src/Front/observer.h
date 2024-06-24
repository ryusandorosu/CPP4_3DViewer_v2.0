#ifndef CPP4_3DVIEWER_V2_0_2_SRC_FRONT_OBSERVER_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_FRONT_OBSERVER_H_

class Observer {
 public:
  virtual void update() = 0;
};

class Observable {
 public:
  void addObserver(Observer *observer) { observers.push_back(observer); }

  void removeObserver(Observer *observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer),
                    observers.end());
  }

  void notifyObservers() {
    for (Observer *observer : observers) {
      observer->update();
    }
  }

 private:
  std::vector<Observer *> observers;
};

#endif  // CPP4_3DVIEWER_V2_0_2_SRC_FRONT_OBSERVER_H_
