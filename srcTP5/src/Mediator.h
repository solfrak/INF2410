#include <iostream>
#include <string>

class BaseComponent;
class Mediator {
 public:
  virtual void Notify(BaseComponent *sender, std::string event) const = 0;
};


class BaseComponent {
 protected:
  Mediator *mediator_;

 public:
  BaseComponent(Mediator *mediator = nullptr) : mediator_(mediator) {
  }

  void set_mediator(Mediator *mediator) {
    this->mediator_ = mediator;
  }
};

class Professeur : public BaseComponent {
 public:
  void EnvoyerNote() {
    std::cout << "Le professeur envoie des notes.\n";
    this->mediator_->Notify(this, "P");
  }
};

class Student : public BaseComponent {
 public:
  void voirNote() {
    std::cout << "L'étudiant veut voir ses notes.\n";
    this->mediator_->Notify(this, "S");
  }
};

class DataBase : public BaseComponent {
 public:
  void accessData() {
    std::cout << "va cherche les notes dans la base de données.\n";
  }
  void saveData(){
    std::cout << "enregitre les notes dans la base de données.\n";
  }
};

class ConcreteMediator : public Mediator {
 private:
  Professeur *professeur_;
  Student *student_;
  DataBase *data_;

 public:
  ConcreteMediator(Professeur *c1, Student *c2, DataBase *c3) : professeur_(c1), student_(c2), data_(c3) {
    this->professeur_->set_mediator(this);
    this->student_->set_mediator(this);
  }
  void Notify(BaseComponent *sender, std::string event) const override {
    if (event == "P") {
      std::cout << "Le mediateur reagie à l'action du prof et ";
      data_->saveData();
    }
    if (event == "S") {
      std::cout << "Le médiateur réagie à l'action de l'étudiant et ";
      data_->accessData();
    }
  }
};