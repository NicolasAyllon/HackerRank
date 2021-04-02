#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Solution
class Message {
public: 
    // Default Constructor
    // Assigns messageID to track order of creation
    Message() {
        currentMessageCount++;
        messageID = currentMessageCount;
        message_text = "";
    }
    // Parameterized Constructor
    // Assigns messageID to track order of creation and initilizes text
    Message(string text) {
      currentMessageCount++;
      messageID = currentMessageCount;
      message_text = text;
    }
    const string& get_text() const { return message_text; }
    // get_ID must be marked as a const member function so it can be called in operator< on const Message& argument
    const int& get_ID() const { return messageID; }

  private:
    static int currentMessageCount; 
    // make static to count messges created across all instances of the class
    int messageID;
    // each instance has its own messageID and message_text
    string message_text; 
};
// Initialize static member of Message out of line
int Message::currentMessageCount = 0;

// Mandatory operator overload < for sorting messages by their IDs
inline bool operator< (const Message& a, const Message& b) { return a.get_ID() < b.get_ID(); }
// Other operators for the sake of completion
inline bool operator==(const Message& a, const Message& b) { return a.get_ID() == b.get_ID(); }
inline bool operator!=(const Message& a, const Message& b) { return !operator==(a, b); }
inline bool operator> (const Message& a, const Message& b) { return operator<(b, a); }
inline bool operator>=(const Message& a, const Message& b) { return !operator<(a, b); }
inline bool operator<=(const Message& a, const Message& b) { return !operator>(a, b); }

// Creates messages
class MessageFactory {
public:
    MessageFactory() {}
    Message create_message(const string& text) {
        Message m = Message(text);
        return m;
    }
};

class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
    // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());         
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};



int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}
