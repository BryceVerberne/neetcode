class Person {
private:
    string lastName;
    int age;
    bool married;

public:
    Person(string lastName, int age, bool married) 
        : lastName(lastName), age(age), married(married) {}

    string getLastName() {
        return lastName;
    }

    int getAge() {
        return age;
    }

    bool isMarried() {
        return married;
    }
};

class PersonFilter {
public:
    virtual ~PersonFilter() {}
    virtual bool apply(Person& person) = 0;
};

class AdultFilter : public PersonFilter {
    bool apply(Person& person) {
        if (person.getAge() >= 18) {
            return true;
        }

        return false;
    }
};

class SeniorFilter : public PersonFilter {
    bool apply(Person& person) {
        if (person.getAge() >= 65) {
            return true;
        }

        return false;
    }
};

class MarriedFilter : public PersonFilter {
    bool apply(Person& person) {
        return person.isMarried();
    }
};

class PeopleCounter {
private:
    PersonFilter* filter;

public:
    void setFilter(PersonFilter& filter) {
        this->filter = &filter;
    }

    int count(vector<Person>& people) {
        int count = 0;

        for (Person& p : people) {
            if (filter->apply(p)) {
                count++;
            }
        }

        return count;
    }
};
