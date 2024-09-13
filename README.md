# MallFeatures

### C++ Implementation

This project is a Mall Management System implemented in C++. It allows users to interact with the system through a console-based interface. Users can browse and select items, add them to a shopping cart, view the total amount, and generate a detailed bill.

#### Features

1. **Login and Registration:**
   - Users can register with a username and password.
   - Registered users can log in to access the main menu.

2. **Main Menu:**
   - Users can choose an item type (Electronics, Eatables, Drinkables, Others) from a menu.
   - Items of the selected type are displayed.
   - Users can add items to the shopping cart.
   - The user can exit the menu.

3. **Shopping Cart:**
   - Users can view their selected items and quantities.
   - Users can remove items from the cart.
   - Users can view the total amount.

4. **Checkout:**
   - Users can proceed to checkout after reviewing their selected items.
   - A bill with user details, selected items, and payment information is generated.
   - The bill is displayed for the user.

### GUI Implementation (Python)

This part of the project adds a graphical user interface (GUI) to the Mall Management System implemented in Python using the Tkinter library.

#### Features

1. **Login and Registration:**
   - Users can register with a username and password.
   - Registered users can log in to access the main menu.

2. **Main Menu:**
   - Users can choose an item type (Electronics, Eatables, Drinkables, Others) from a dropdown menu.
   - Items of the selected type are displayed in a table format.
   - Double-clicking an item adds it to the shopping cart.
   - Right-clicking an item shows its details.
   - Keyboard shortcuts (Enter and Delete) are supported for adding items.

3. **Shopping Cart:**
   - Users can view their selected items and quantities in a table format.
   - Double-clicking an item removes it from the cart.
   - Keyboard shortcuts (Enter, Delete, Arrow keys) are supported for navigation and removal.

4. **Total Amount:**
   - Users can view the total amount paid for items in the shopping cart.

5. **Checkout:**
   - Users can proceed to checkout after reviewing their selected items.
   - A bill with user details, selected items, and payment information is generated.
   - The bill is saved as a text file for future reference.

#### How to Run

1. Install Python: Make sure you install Python on your system. If not, you can download it from the official Python website: [Python Downloads](https://www.python.org/downloads/).

2. Clone the Repository: Clone this GitHub repository to your local machine.

   ```
   https://github.com/KuldeepBijarniya/MallFeatures.git
   ```

3. Navigate to the Project Directory: Use the terminal or command prompt to navigate the project directory.

   ```
   cd Mall-Management-System
   ```

4. Install Required Libraries: The GUI part uses the Tkinter library for GUI. Tkinter is usually included with standard Python installations.

5. Run the Application: Run the Python script `MallFeaturesGUI.py` using the following command:

   ```
   python MallFeaturesGUI.py
   ```

6. Use the Application: The application's GUI will open. You can register, log in, and explore the mall's items, add them to the cart, and check out.

**Note:** The project's GUI functionality may vary based on the Python environment and OS you're using.
