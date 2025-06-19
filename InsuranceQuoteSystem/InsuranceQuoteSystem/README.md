# Insurance Quote System

### 👤 Student: [Your Name]  
### 📅 Date: [Insert Date]

## 🧾 Description

This C++ project calculates insurance premiums based on applicant age and vehicle type using a bracket system. It demonstrates the use of structs, abstract classes, dynamic memory, pointer arithmetic, and polymorphism.

## ✅ Features

- Uses `struct` for Applicant and Bracket
- Dynamic allocation for premium brackets
- Inheritance from abstract class `QuoteEngine`
- Derived classes: `BasicQuoteEngine`, `PremiumQuoteEngine`
- Pointer arithmetic for bracket searching
- Polymorphic dispatch with `QuoteEngine**`
- Functions to dynamically add/remove brackets

## 🧪 Sample Output

- Basic Quote: \$800
- Premium Quote: \$1000

## 📁 Files

- `main.cpp`: Source code
- `README.md`: This file
- `output_screenshots/`: Folder for output screenshots (add your own)

## 🛠️ Compile & Run

```bash
g++ main.cpp -o insurance_quote
./insurance_quote
```

## 🧹 Memory Management

All dynamically allocated memory is properly deallocated.
