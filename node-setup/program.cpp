#include <iostream>
#include <fstream>
using namespace std;

void makeGitignore();
void makeJsFiles();
void setupBasicNodeStructure();
void installModules();
void deleteFolderStructure();

int main() {
    int i;
    cout << "\n---------------------------------------------" << endl;
    cout << "1. Setup basic node-express structure" << endl;
    cout << "2. Setup full node-express folder structure" << endl;
    cout << "3. Delete all node setup files." << endl;
    cout << "\nWhat you want to do ? ";
    cin >> i;

    switch (i) {
    case 1:
        makeGitignore();
        makeJsFiles();
        installModules();
        break;
    case 2:
        makeGitignore();
        makeJsFiles();
        setupBasicNodeStructure();
        system("npm install ejs");
        installModules();
        break;
    case 3:
        deleteFolderStructure();
        break;

    default:
        cout << "Invalid input" << endl;
        break;
    }
    return 0;
}

void makeJsFiles() {
    // Create and open a text file
    ofstream MyFile("server.js");
    // Write to the file
    MyFile << "const express = require('express')\nconst app = express()\nconst port = 3000\napp.get('/', (req, res) = > {\nres.send('Hello World!')\n})\napp.listen(port, () = > {\nconsole.log(`Example app listening at http ://localhost:${port}`)\n})";

    MyFile.close();
}

void makeGitignore() {
    // Create and open a text file
    ofstream gitFile(".gitignore");
    // Write to the file
    gitFile << "node_modules/";

    gitFile.close();
}

void setupBasicNodeStructure() {
    system("mkdir views");
    system("mkdir public");
    system("mkdir routes");
}

void installModules() {
    system("npm install express");
    system("npm install --save-dev nodemon");
    system("npm init -y");
}

void deleteFolderStructure() {
    system("rmdir node_modules");
    system("del server.js");
    system("del package.json");
    system("del package-lock.json");
    system("rmdir views");
    system("rmdir public");
    system("rmdir routes");
}