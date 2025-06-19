#include <iostream>
#include <cstring>

using namespace std;

// Struct for the applicant
struct Applicant {
    char vin[17];
    int age;
    char vehicleType[10];
};

// Struct for the age premium bracket
struct Bracket {
    float minAge;
    float maxAge;
    float premium;
};

// Function declarations for dynamic bracket management
void addBracket(Bracket* &brackets, int &count, Bracket newBracket);
void removeBracket(Bracket* &brackets, int &count, int index);

// Global brackets and count
Bracket* brackets = nullptr;
int bracketCount = 0;

// Abstract class
class QuoteEngine {
public:
    virtual float calculate(const Applicant* applicant) = 0;
    virtual ~QuoteEngine() {}
};

// Basic quote engine
class BasicQuoteEngine : public QuoteEngine {
public:
    float calculate(const Applicant* applicant) override {
        for (int i = 0; i < bracketCount; i++) {
            if ((brackets + i)->minAge <= applicant->age &&
                applicant->age <= (brackets + i)->maxAge) {
                return (brackets + i)->premium;
            }
        }
        return -1.0f;
    }
};

// Premium quote engine (adds 25%)
class PremiumQuoteEngine : public QuoteEngine {
public:
    float calculate(const Applicant* applicant) override {
        for (int i = 0; i < bracketCount; i++) {
            if ((brackets + i)->minAge <= applicant->age &&
                applicant->age <= (brackets + i)->maxAge) {
                return (brackets + i)->premium * 1.25f;
            }
        }
        return -1.0f;
    }
};

// Function to add a new bracket
void addBracket(Bracket* &brackets, int &count, Bracket newBracket) {
    Bracket* temp = new Bracket[count + 1];
    for (int i = 0; i < count; i++) {
        temp[i] = brackets[i];
    }
    temp[count] = newBracket;
    delete[] brackets;
    brackets = temp;
    count++;
}

// Function to remove a bracket by index
void removeBracket(Bracket* &brackets, int &count, int index) {
    if (index < 0 || index >= count) return;
    Bracket* temp = new Bracket[count - 1];
    for (int i = 0, j = 0; i < count; i++) {
        if (i != index) {
            temp[j++] = brackets[i];
        }
    }
    delete[] brackets;
    brackets = temp;
    count--;
}

// Main function
int main() {
    // Add brackets
    addBracket(brackets, bracketCount, {18, 25, 1000});
    addBracket(brackets, bracketCount, {26, 40, 800});
    addBracket(brackets, bracketCount, {41, 60, 600});

    // Create sample applicant
    Applicant applicant;
    strcpy(applicant.vin, "1HGCM82633A004352");
    applicant.age = 30;
    strcpy(applicant.vehicleType, "car");

    // Create engines
    QuoteEngine** engines = new QuoteEngine*[2];
    engines[0] = new BasicQuoteEngine();
    engines[1] = new PremiumQuoteEngine();

    // Display results
    for (int i = 0; i < 2; i++) {
        float quote = engines[i]->calculate(&applicant);
        cout << "Engine " << (i == 0 ? "Basic" : "Premium") << " Quote: $" << quote << endl;
    }

    // Clean up
    for (int i = 0; i < 2; i++) {
        delete engines[i];
    }
    delete[] engines;
    delete[] brackets;

    return 0;
}
