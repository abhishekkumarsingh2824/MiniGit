#include <bits/stdc++.h>
using namespace std;

/*
    Commit Node (Binary Tree)
*/
class Commit {
public:
    int id;
    string message;

    Commit* next1;   // first child
    Commit* next2;   // second child (branch case)

    Commit(int i, string msg) {
        id = i;
        message = msg;
        next1 = NULL;
        next2 = NULL;
    }
};

/*
    Branch Node (Linked List)
*/
class Branch {
public:
    string name;
    Commit* head;
    Branch* next;

    Branch(string n, Commit* h) {
        name = n;
        head = h;
        next = NULL;
    }
};

/*
    Mini Git System
*/
class MiniGit {

private:

    Commit* root;
    Commit* current;

    Branch* branchList;

    stack<Commit*> undoStack;
    stack<Commit*> redoStack;

    vector<string> files;

    int commitCount;

public:

    MiniGit() {
        root = NULL;
        current = NULL;
        branchList = NULL;
        commitCount = 0;
    }

    // Initialize repository
    void initRepo() {

        root = new Commit(commitCount++, "Initial Commit");
        current = root;

        undoStack.push(root);

        cout << "Repository Initialized Successfully\n";
    }

    // Add file
    void addFile(string fileName) {

        files.push_back(fileName);

        cout << "File Added: " << fileName << endl;
    }

    // Commit changes
    void makeCommit(string msg) {

        Commit* newCommit = new Commit(commitCount++, msg);

        if (current->next1 == NULL)
            current->next1 = newCommit;
        else
            current->next2 = newCommit;

        current = newCommit;

        undoStack.push(current);

        while (!redoStack.empty())
            redoStack.pop();

        cout << "Commit Done: " << msg << endl;
    }

    // Show history (DFS)
    void showHistory(Commit* node) {

        if (node == NULL)
            return;

        cout << "Commit ID: " << node->id
             << " | Message: " << node->message << endl;

        showHistory(node->next1);
        showHistory(node->next2);
    }

    void log() {
        cout << "\n====== Commit History ======\n";
        showHistory(root);
    }

    // Undo
    void undo() {

        if (undoStack.size() <= 1) {
            cout << "Nothing to undo\n";
            return;
        }

        redoStack.push(undoStack.top());
        undoStack.pop();

        current = undoStack.top();

        cout << "Undo Successful\n";
    }

    // Redo
    void redo() {

        if (redoStack.empty()) {
            cout << "Nothing to redo\n";
            return;
        }

        Commit* temp = redoStack.top();
        redoStack.pop();

        undoStack.push(temp);
        current = temp;

        cout << "Redo Successful\n";
    }

    // Create Branch
    void createBranch(string name) {

        Branch* newBranch = new Branch(name, current);

        if (branchList == NULL) {
            branchList = newBranch;
        } else {
            Branch* temp = branchList;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newBranch;
        }

        cout << "Branch Created: " << name << endl;
    }

    // Switch Branch
    void switchBranch(string name) {

        Branch* temp = branchList;

        while (temp != NULL) {

            if (temp->name == name) {
                current = temp->head;
                cout << "Switched to Branch: " << name << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "Branch Not Found\n";
    }

    // Revert to commit
    void revertCommit(int id) {

        stack<Commit*> tempStack;
        bool found = false;

        while (!undoStack.empty()) {

            Commit* top = undoStack.top();
            tempStack.push(top);
            undoStack.pop();

            if (top->id == id) {
                current = top;
                found = true;
                break;
            }
        }

        while (!tempStack.empty()) {
            undoStack.push(tempStack.top());
            tempStack.pop();
        }

        if (found)
            cout << "Reverted to Commit ID: " << id << endl;
        else
            cout << "Commit Not Found\n";
    }
};


/*
    Main Menu
*/
int main() {

    MiniGit git;

    int choice;
    string fileName, message, branchName;
    int commitID;

    while (true) {

        cout << "\n========== MINI GIT ==========\n";
        cout << "1. Initialize Repository\n";
        cout << "2. Add File\n";
        cout << "3. Commit\n";
        cout << "4. Show Log\n";
        cout << "5. Undo\n";
        cout << "6. Redo\n";
        cout << "7. Create Branch\n";
        cout << "8. Switch Branch\n";
        cout << "9. Revert to Commit\n";
        cout << "0. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {

        case 1:
            git.initRepo();
            break;

        case 2:
            cout << "Enter File Name: ";
            getline(cin, fileName);
            git.addFile(fileName);
            break;

        case 3:
            cout << "Enter Commit Message: ";
            getline(cin, message);
            git.makeCommit(message);
            break;

        case 4:
            git.log();
            break;

        case 5:
            git.undo();
            break;

        case 6:
            git.redo();
            break;

        case 7:
            cout << "Enter Branch Name: ";
            getline(cin, branchName);
            git.createBranch(branchName);
            break;

        case 8:
            cout << "Enter Branch Name: ";
            getline(cin, branchName);
            git.switchBranch(branchName);
            break;

        case 9:
            cout << "Enter Commit ID: ";
            cin >> commitID;
            git.revertCommit(commitID);
            break;

        case 0:
            return 0;

        default:
            cout << "Invalid Choice\n";
        }
    }
}