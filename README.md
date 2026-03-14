# Mini Git System (C++)

A simplified implementation of a **Git-like version control system** built in **C++** using core data structures such as **Binary Trees, Linked Lists, Stacks, and Vectors**.

This project simulates fundamental Git operations like **commits, branching, undo/redo, and history tracking**.

---

# 🚀 Features

* Initialize a repository
* Add files to staging
* Create commits with messages
* View commit history
* Undo last commit
* Redo undone commits
* Create new branches
* Switch between branches
* Revert to a specific commit

---

# 🧠 Data Structures Used

| Data Structure | Purpose                           |
| -------------- | --------------------------------- |
| Binary Tree    | Stores commit history             |
| Linked List    | Maintains branches                |
| Stack          | Implements Undo / Redo operations |
| Vector         | Stores added files                |

---

# 🏗️ Project Architecture

## 1. Commit Node (Binary Tree)

Represents a commit in the system.

Each commit contains:

* Commit ID
* Commit message
* Pointer to next commits (branching support)

```cpp
class Commit {
public:
    int id;
    string message;
    Commit* next1;
    Commit* next2;
};
```

---

## 2. Branch Node (Linked List)

Represents branches in the repository.

Each branch contains:

* Branch name
* Pointer to the head commit

```cpp
class Branch {
public:
    string name;
    Commit* head;
    Branch* next;
};
```

---

## 3. MiniGit Class

The core system managing repository operations.

### Main Components

* Root commit
* Current commit pointer
* Branch list
* Undo stack
* Redo stack
* File storage

---

# 📌 Supported Operations

## Initialize Repository

Creates the first commit.

```
git.initRepo()
```

Output:

```
Repository Initialized Successfully
```

---

## Add File

Adds a file to the system.

```
git.addFile("file.txt")
```

Output:

```
File Added: file.txt
```

---

## Commit Changes

Creates a new commit node.

```
git.makeCommit("Added new feature")
```

Output:

```
Commit Done: Added new feature
```

---

## Show Commit History

Displays commit history using **DFS traversal**.

```
git.log()
```

Output example:

```
====== Commit History ======
Commit ID: 0 | Message: Initial Commit
Commit ID: 1 | Message: Added login
Commit ID: 2 | Message: Fixed bug
```

---

## Undo Commit

Moves back to the previous commit.

```
git.undo()
```

Output:

```
Undo Successful
```

---

## Redo Commit

Restores previously undone commit.

```
git.redo()
```

Output:

```
Redo Successful
```

---

## Create Branch

Creates a new branch from the current commit.

```
git.createBranch("feature")
```

Output:

```
Branch Created: feature
```

---

## Switch Branch

Changes the working branch.

```
git.switchBranch("feature")
```

Output:

```
Switched to Branch: feature
```

---

## Revert to Commit

Moves repository to a specific commit.

```
git.revertCommit(commitID)
```

Output:

```
Reverted to Commit ID: X
```

---

# 🖥️ Menu Interface

The program runs using a **console-based menu system**:

```
========== MINI GIT ==========
1. Initialize Repository
2. Add File
3. Commit
4. Show Log
5. Undo
6. Redo
7. Create Branch
8. Switch Branch
9. Revert to Commit
0. Exit
```

---

# 🛠️ Technologies Used

* **C++**
* Standard Template Library (STL)

  * vector
  * stack
* Data Structures

  * Binary Tree
  * Linked List

---

# 📂 How to Run

Compile the program:

```
g++ mini_git.cpp -o mini_git
```

Run:

```
./mini_git
```

---

# 🎯 Learning Objectives

This project demonstrates:

* Implementation of **Version Control concepts**
* Use of **Data Structures in system design**
* Understanding of **Undo / Redo mechanisms**
* Simulation of **Git branching logic**

---

# 🔮 Future Improvements

Possible enhancements:

* Merge branches
* Delete branches
* Visual commit tree
* File diff system
* Save commits to disk
* Implement merge conflicts

---

# 👨‍💻 Author

**Abhishek Kumar Singh**

---

# ⭐ Contribution

Contributions and improvements are welcome.
Feel free to fork the repository and submit a pull request.
