class Observer {
public:
    virtual void notify(string& itemName) = 0;
};

class Customer : public Observer {
private:
    string name;
    int notifications;

public:
    Customer(string& name) : name(name), notifications(0) {}

    void notify(string& itemName) override {
        notifications += 1;
    }

    int countNotifications() {
        return notifications;
    }
};

class OnlineStoreItem {
private:
    vector<Observer*> subscribers;
    string itemName;
    int stock;

public:
    OnlineStoreItem(string& itemName, int stock) : itemName(itemName), stock(stock) {}

    void subscribe(Observer* observer) {
        if (observer) {
            subscribers.push_back(observer);
        }
    }

    void unsubscribe(Observer* observer) {
        for (auto it = subscribers.begin(); it != subscribers.end(); ++it) {
            if (observer == *it) {
                subscribers.erase(it);
                break;
            }
        }
    }

    void updateStock(int newStock) {
        if ((this->stock == 0) && (newStock > 0)) {
            // Notify observers
            for (Observer* observer : subscribers) {
                observer->notify(this->itemName);
            }
        }
        this->stock = newStock;
    }
};
