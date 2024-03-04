#include <iostream>
#include <fstream>
#include <unordered_map>
#include <cctype>
#include <algorithm>
#include <string>
using namespace std;

  // to display the menu options
  void displayMenu() {
      cout << "Menu:\n";
      cout << "1. Search frequency of an item" << endl;
      cout << "2. Print item frequency list" << endl;
      cout << "3. Print item frequency histogram" << endl;
      cout << "4. Exit" << endl;
      cout << "Enter number of your choice: ";
  }

  // to create a backup file
  void createDataFile(const unordered_map<string, int>& itemFrequency) {
      ofstream outputFile("frequency.dat"); // creates and opens the output file
      if (outputFile.is_open()) {
          // writes the item frequencies to the output file
          for (const auto& pair : itemFrequency) {
              outputFile << pair.first << " " << pair.second << endl;
          }
          outputFile.close();
          cout << "Data file created successfully: frequency.dat" << endl;
      }
      else {
          cout << "Error creating data file!\n";
      }
  }

  // reads the input file and gets the item frequencies
  unordered_map<string, int> readInputFile(const string& filename) {
      ifstream inputFile(filename); // Open the input file
      unordered_map<string, int> itemFrequency;
      if (inputFile.is_open()) {
          string item;
          while (inputFile >> item) {
              itemFrequency[item]++; // increments item frequency
          }
          inputFile.close();
      }
      else {
          cout << "Error! Cannot open input file: " << filename << endl;
      }
      return itemFrequency;
  }

  // option 1: find the frequency of a specific item
  int findItemFrequency(const unordered_map<string, int>& itemFrequency, const string& item) {
      if (itemFrequency.count(item) > 0) {
          return itemFrequency.at(item);
      }
      return 0; // if the item is not found, return 0
  }

  // option 2: print the frequency of all items
  void printItemFrequencyList(const unordered_map<string, int>& itemFrequency) {
      cout << "Item Frequency List" << endl;
      cout << "**********" << endl;
      for (const auto& pair : itemFrequency) {
          cout << pair.first << " " << pair.second << endl;
      }
  }

  // option 3: print a histogram of the frequencies of all items using *
  void printItemFrequencyHistogram(const unordered_map<string, int>& itemFrequency) {
      cout << "Item Frequency Histogram" << endl;
      cout << "**********" << endl;
      for (const auto& pair : itemFrequency) {
          cout << pair.first << " ";
          for (int i = 0; i < pair.second; i++) {
              cout << "*"; 
          }
          cout << "\n";
      }
  }


int main() {
    // to get item frequencies
    unordered_map<string, int> itemFrequency = readInputFile("CS210_Project_Three_Input_File.txt");

    // to create a backup file
    createDataFile(itemFrequency);

    int choice;
    string item;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
          case 1:
              cout << "Enter the name of the item to find its frequency: ";
              cin >> item;
              if (!item.empty()) {
                  item[0] = toupper(item[0]);
                  cout << "Frequency of " << item << ": " << findItemFrequency(itemFrequency, item) << endl;
                  break;
              }
          case 2:
              printItemFrequencyList(itemFrequency);
              break;
          case 3:
              printItemFrequencyHistogram(itemFrequency);
              break;
          case 4:
              cout << "Exiting the program..." << endl;
              break;
          default:
              cout << "Invalid choice! Please try again." << endl;
              break;
        }

        cout << endl;
    } while (choice != 4);

    return 0;
}
