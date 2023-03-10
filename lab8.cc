// Name: Daylen Allen
// Lab8: Section 104
// Github: Hacked5
// Email: da135021@ohio.edu

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
// When the program is ran the user will see this
void displayMenu()
{
    cout << "\n1. Set the shift key value (default is 3)" << endl;
    cout << "2. Encrypt a file" << endl;
    cout << "3. Decrypt a file" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice: ";
}
// How the file gets encrypted
string encrypt(string message, int key)
{
    string result = "";
    for (int i = 0; i < message.length(); i++)
    {
        if (isalpha(message[i]))
        {
            char c = (toupper(message[i]) - 'A' + key) % 26 + 'A';
            result += c;
        }
        else
        {
            result += message[i];
        }
    }
    return result;
}
// How the file gets decrypted
string decrypt(string message, int key)
{
    string result = "";
    for (int i = 0; i < message.length(); i++)
    {
        if (isalpha(message[i]))
        {
            char c = (toupper(message[i]) - 'A' - key + 26) % 26 + 'A';
            result += c;
        }
        else
        {
            result += message[i];
        }
    }
    return result;
}
// If the user chooses to change the shift key
void setKey(int &key)
{
    cout << "Enter a shift key between 1 and 10: ";
    cin >> key;
    // If the number is less than 1 or greater than ten it will output this
    while (key < 1 || key > 10)
    {
        cout << "Invalid input. Enter a shift key between 1 and 10: ";
        cin >> key;
    }
}
// If the user chooses to encrypt a file
void encryptFile(int key)
{
    string filename, line, message;
    cout << "Enter the name of the file to encrypt: ";
    cin >> filename;
    // If the input file cannot open
    ifstream inputStream(filename.c_str());
    if (!inputStream)
    {
        cout << "Cannot open input file." << endl;
        return;
    }
    // How the file gets encrypted
    while (getline(inputStream, line))
    {
        message += line + '\n';
    }

    inputStream.close();

    message = encrypt(message, key);
    // If the output file cannot open
    ofstream outputStream((filename + ".enc").c_str());
    if (!outputStream)
    {
        cout << "Cannot open output file." << endl;
        return;
    }

    outputStream << message;

    outputStream.close();
    // What the user will see
    cout << "Encryption successful. Encrypted file saved as " << filename << ".enc" << endl;
}
// If the user chooses to decrypt a file
void decryptFile(int key)
{
    string filename, line, message;
    cout << "Enter the name of the file to decrypt: ";
    cin >> filename;
    // If the input file cannot open
    ifstream inputStream(filename.c_str());
    if (!inputStream)
    {
        cout << "Cannot open input file." << endl;
        return;
    }
    // How the file gets decrypted
    while (getline(inputStream, line))
    {
        message += line + '\n';
    }

    inputStream.close();

    message = decrypt(message, key);
    // If the output file cannot open
    ofstream outputStream((filename + ".dec").c_str());
    if (!outputStream)
    {
        cout << "Cannot open output file." << endl;
        return;
    }

    outputStream << message;

    outputStream.close();
    // What the user will see
    cout << "Decryption successful. Decrypted file saved as " << filename << ".dec" << endl;
}
// The main program

int main()
{
    // How the programs main menu options work

    int choice, key = 3;
    do
    {
        displayMenu();
        cin >> choice;
        if (choice == 1)
        {
            setKey(key);
        }
        else if (choice == 2)
        {
            encryptFile(key);
        }
        else if (choice == 3)
        {
            decryptFile(key);
        }
    } while (choice != 4);
    return 0;
}
