class Charity:
    def __init__(self, name):
        self.name = name

class Donation:
    def __init__(self, charity, amount):
        self.charity = charity
        self.amount = amount

class DonationManager:
    def __init__(self):
        self.donations = []  
        self.pending_donations = []  
        self.charities = [] 

    def add_charity(self, charity_name):
        charity = Charity(charity_name)
        self.charities.append(charity)

    def donate(self, charity_name, amount):
        charity = next((c for c in self.charities if c.name == charity_name), None)
        if charity:
            donation = Donation(charity, amount)
            self.pending_donations.append(donation)
            print(f"Donation of ${amount} to {charity_name} is pending.")
        else:
            print("Charity not found.")

    def process_donation(self):
        if self.pending_donations:
            donation = self.pending_donations.pop(0)  
            self.donations.append(donation)  # Add to stack for undo
            print(f"Processed donation of ${donation.amount} to {donation.charity.name}.")
        else:
            print("No pending donations to process.")

    def undo_donation(self):
        if self.donations:
            donation = self.donations.pop()  # LIFO
            self.pending_donations.insert(0, donation)  
            print(f"Undid donation of ${donation.amount} to {donation.charity.name}.")
        else:
            print("No donations to undo.")

    def show_charities(self):
        print("Charities:")
        for charity in self.charities:
            print(f"- {charity.name}")

    def show_pending_donations(self):
        print("Pending Donations:")
        for donation in self.pending_donations:
            print(f"- ${donation.amount} to {donation.charity.name}")

    def show_donations(self):
        print("Processed Donations:")
        for donation in self.donations:
            print(f"- ${donation.amount} to {donation.charity.name}")

def main():
    manager = DonationManager()
    
    while True:
        print("\n1. Add Charity")
        print("2. Donate")
        print("3. Process Donation")
        print("4. Undo Donation")
        print("5. Show Charities")
        print("6. Show Pending Donations")
        print("7. Show Processed Donations")
        print("8. Exit")

        choice = input("Enter your choice: ")

        if choice == '1':
            name = input("Enter charity name: ")
            manager.add_charity(name)
        elif choice == '2':
            name = input("Enter charity name: ")
            amount = float(input("Enter donation amount: "))
            manager.donate(name, amount)
        elif choice == '3':
            manager.process_donation()
        elif choice == '4':
            manager.undo_donation()
        elif choice == '5':
            manager.show_charities()
        elif choice == '6':
            manager.show_pending_donations()
        elif choice == '7':
            manager.show_donations()
        elif choice == '8':
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
