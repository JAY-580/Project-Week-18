# Project-Week-18 ：學生成績管理系統（Student Grades Management System）

## 功能：

#### 1. 新增學生資料
#### 2. 列出所有學生資料
#### 3. 依成績排序
#### 4. 查詢學生資料
#### 5. 成績統計

---

## 如何編譯

請先開啟終端機（Terminal）並切換至專案資料夾。

輸入以下指令進行編譯：

```bash
g++ -std=c++17 main.cpp -o main
```

若編譯成功，將會產生執行檔：

### Windows

```text
main.exe
```

## 如何執行

### Windows

```bash
main.exe
```

---

## 操作選單


使用者輸入對應數字即可執行功能。

---

## 執行範例

```text
Enter choice: 1

Enter ID: S001
Enter Name: Eric Chong
Enter Score: 95

Student added successfully.
```

```text
Enter choice: 5

===== Statistics =====

Average Score : 85.50
Highest Score : 95
Lowest Score  : 76
Pass Count    : 4
Fail Count    : 1
```
---

## 使用技術：

* Struct（結構）
* Vector（STL 容器）
* Sort（STL Algorithm）
* Lambda Expression
* Template Function
* Function Modular Design
