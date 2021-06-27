# Database

| Topic | Article |
| :--: | :--: |
| ETL | [Read Here](https://cofounderstown.com/etls-why-use-cd2f4) |

# DBMS Notes

## What is DBMS
A database is a collection of information that is organized so that it can be easily accessed, managed and updated. Computer databases typically contain aggregations of data records or files, containing information about sales transactions or interactions with specific customers.

## DBMS V/S File System
![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/dbms/1.png)
![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/dbms/2.png)

## SQL vs NoSQL
**Schema:** A database schema is the skeleton structure that represents the logical view of the entire database. It defines how the data is organized and how the relations among them are associated. It formulates all the constraints that are to be applied on the data.
- JOIN’s are hard in NoSQL
- SQL Databases are built for JOIN’s.
- For write heavy we can prefer NoSQL, over SQL DB due to speed and managing power and we can easily insert data in a block.
- For Aggregation and redundancy NoSQL provides a better way.


|   | SQL  | NoSQL  |
|---|---|---|
|   | Relational | Not Relational |
|   | Follows ACID properties | Not follow ACID properties |
| Scalability | Vertical (Larger instance) | Horizontal(Sharding) |
| Schema | Rigid & Consistent | Flexible & Dynamic |
|  | Not necessarily follows CAP theorem | Follows CAP Theorem |
|  | Good for complex queries | Not good for complex queries |
|  | Write Heavy | Read Heavy |
|  | OLAP | OLTP |
|  | Normalized | Not Normalized |

## OLAP V/S OLTP
**OLTP** (It is an online transactional system and manages database modification.), SQL DB prefer
**OLAP** (It is an online data retrieving and data analysis system.), NoSQL

## ACID Properties
A transaction is a single logical unit of work which accesses and possibly modifies the contents of a database. Transactions access data using read and write operations.
In order to maintain consistency in a database, before and after the transaction, certain properties are followed. These are called ACID properties.

- **Atomicity:** By this, we mean that either the entire transaction takes place at once or doesn’t happen at all. There is no midway i.e. transactions do not occur partially. Each transaction is considered as one unit and either runs to completion or is not executed at all. It involves the following two operations.
Abort: If a transaction aborts, changes made to the database are not visible.
Commit: If a transaction commits, changes made are visible.
Atomicity is also known as the ‘All or nothing rule’.

- **Consistency:** This means that integrity constraints must be maintained so that the database is consistent before and after the transaction. It refers to the correctness of a database.
- **Isolation:** This property ensures that multiple transactions can occur concurrently without leading to the inconsistency of database state. Transactions occur independently without interference. Changes occurring in a particular transaction will not be visible to any other transaction until that particular change in that transaction is written to memory or has been committed. This property ensures that the execution of transactions concurrently will result in a state that is equivalent to a state achieved if these were executed serially in some order. (Concurrently Serializable).
- **Durability:** This property ensures that once the transaction has completed execution, the updates and modifications to the database are stored in and written to disk and they persist even if a system failure occurs. These updates now become permanent and are stored in non-volatile memory. The effects of the transaction, thus, are never lost.

## Data Abstraction
**Data Abstraction** refers to the process of hiding irrelevant details from the user. So, what is the meaning of irrelevant details. For eg different website views for different users like admin, student and faculty. 
- There are mainly three levels of data abstraction and we divide it into three levels in order to achieve Data Independence. Data Independence means users and data should not directly interact with each other.
- Three levels of data abstraction:
    - View Level:- Different view for different users like marks and attendance for students but different for faculty.
    - Conceptual Level (Logical):- This level tells how the data is actually stored and structured. We have different data models by which we can store the data
    - Physical Level (Internal):- As the name suggests, the Physical level tells us where the data is actually stored i.e. it tells the actual location of the data that is being stored by the user. The Database Administrators(DBA) decide which data should be kept at which particular disk drive, how the data has to be fragmented, where it has to be stored etc. They decide if the data has to be centralized or distributed. Though we see the data in the form of tables at view level the data here is actually stored in the form of files only. It totally depends on the DBA, how he/she manages the database at the physical level.

## Data Model:
- Hierarchical Model
- Network Model
- Entity-Relationship Model
- Relational Model
- Object-Oriented Data Model
- Object-Relational Data Model
- Flat Data Model
- Semi-Structured Data Model
- Associative Data Model
- Context Data Model

https://afteracademy.com/blog/what-is-data-model-in-dbms-and-what-are-its-types

## Database Language:
- **DDL** – Data Definition Language (CREATE, DROP, ALTER, TRUNCATE, COMMENT, RENAME)
- **DQL** – Data Query Language (SELECT)
- **DML** – Data Manipulation Language (INSERT, UPDATE, DELETE)
- **DCL** – Data Control Language (GRANT, REVOKE)
- **TCL** – Transaction Control Language (COMMIT, ROLLBACK, SAVEPOINT, SET TRANSACTION)

https://www.quora.com/How-does-a-relational-DBMS-internally-store-its-data-In-what-type-of-data-structure-How-does-it-offer-the-rapid-retrieval-without-loading-the-entire-database-into-the-main-memory-I-have-heard-many-DBMS-use-B-trees

> Keys - (Foreign, Primary, Candidate, Alternate, Super, Secondary)

## Database Optimization Techniques:
- SQL Query optimization
- Indexing
- Sharding (JOINS across different shards is an issue, MEMCACHED is good example of consistent hashing)
- Master Slave Architecture (Master -> Slave and slave for writing, lead to consistency issue).
- Better SELECT query, avoid JOINS, etc.
- Query Caching
- Replicas for read queries and copy
- Sending complete data bundles in one go instead of multiple requests.(Condensed the data query in a single data query). -> gives lesser I/O operations.
- Linked list + Sorted array (at database arch level)

## Hashing
- Hashing is a technique that is used to uniquely identify a specific object from a group of similar objects. Hashing is implemented in two steps:
- An element is converted into an integer by using a hash function. This element can be used as an index to store the original element, which falls into the hash table.
- The element is stored in the hash table where it can be quickly retrieved using a hashed key.
    `hash = hashfunc(key)`
    `index = hash % array_size`
- Collision resolution techniques:
    - **Separate chaining (open hashing)** (Linked list at same place for storing multiple values/occurrences)
    - **Linear probing** (open addressing or closed hashing)
        - `index = index % hashTableSize`
        - `index = (index + 1) % hashTableSize`
        - `index = (index + 2) % hashTableSize`
        - `index = (index + 3) % hashTableSize `
    - Quadratic Probing:
        - `index = index % hashTableSize`
        - `index = (index + 12) % hashTableSize`
        - `index = (index + 22) % hashTableSize`
        - `index = (index + 32) % hashTableSize `
    - Double hashing:
        - `index = (index + 1 * indexH) % hashTableSize`
        - `index = (index + 2 * indexH) % hashTableSize` 

## Indexing:
- A database index is an important auxiliary data structure helping to speed up data retrieval. The amount of data accessed to execute an SQL query is the main factor contributing to the execution time. The use of well-designed indexes minimizes the volume of accessed data.
- Indexes can be categorized in several ways: its structure (**B-tree, hash table, binary, column-store, full-text, etc.**), whether it’s clustered or not, and whether it’s partitioned (locally, globally, or not at all). Some store entire rows, some store derivative values, other store straight column copies.
- A typical index is implemented using a balanced tree structure. Leaf levels of an index are sorted based on column values. So, when we want to find all rows with a specific value of an indexed column, we are able to quickly locate the first one and read consecutive rows as long as they match the value.
- **Partition V/S Index:** Table partitions are defined by criteria that split a table into mutually exclusive collections of rows. An index is an auxiliary structure designed to speed up the retrieval of rows fulfilling search criteria.
Can use multilevel indexing and clustered indexing for improvement.
B-Tree (Balanced Tree):

## Clustered Indexing & Non-Clustered Indexing
1. **Clustered Index:**
Clustered index is created only when both the following conditions satisfy –
    - The data or file, that you are moving into secondary memory should be in sequential or sorted order.
    - There should be non key value, means the data should be unique.

Whenever you apply clustered indexing in a table, it will perform sorting in that table only. You can create only one clustered index in a table like primary key. Clustered index is as same as dictionary where the data is arranged by alphabetical order.
In clustered index, index contains pointer to block but not direct data.
You can have only one clustered index in one table, but you can have one clustered index on multiple columns, and that type of index is called composite index.
![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/dbms/Clustered_Index.jpg)

2. **Non-clustered Index:**
Non-Clustered Index is similar to the index of a book. The index of a book consists of a chapter name and page number, if you want to read any topic or chapter then you can directly go to that page by using index of that book. No need to go through each and every page of a book.
The data is stored in one place, and index is stored in another place. Since, the data and non-clustered index is stored separately, then you can have multiple non-clustered index in a table.
In non-clustered index, index contains the pointer to data.
![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/dbms/Non-clustered_Index.jpg)

## B-Tree & B+-Tree
**B-Tree** is known as a self-balancing tree as its nodes are sorted in the inorder traversal. In **B-tree**, a node can have more than two children. B-tree has a height of logM N (Where ‘M’ is the order of tree and N is the number of nodes). And the height is adjusted automatically at each update. In the B-tree data is sorted in a specific order, with the lowest value on the left and the highest value on the right. To insert the data or key in B-tree is more complicated than a binary tree.
There are some conditions that must be hold by the B-Tree:
- All the leaf nodes of the B-tree must be at the same level.
- Above the leaf nodes of the B-tree, there should be no empty sub-trees.
- B- tree’s height should lie as low as possible.
- B-Tree's are generated from m-way search trees but with some constraints
- ciel(m/2) children
- Root can have minimum 2 children
- Bottom up filling

**B+ Tree**
**B+ tree** eliminates the drawback B-tree used for indexing by storing data pointers only at the leaf nodes of the tree. Thus, the structure of leaf nodes of a B+ tree is quite different from the structure of internal nodes of the B tree. It may be noted here that, since data pointers are present only at the leaf nodes, the leaf nodes must necessarily store all the key values along with their corresponding data pointers to the disk file block, in order to access them. Moreover, the leaf nodes are linked to providing ordered access to the records. The leaf nodes, therefore form the first level of the index, with the internal nodes forming the other levels of a multilevel index. Some of the key values of the leaf nodes also appear in the internal nodes, to simply act as a medium to control the searching of a record.
![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/dbms/Btree.jpg)

**B-Tree V/S B+ Tree**
![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/dbms/b-tree.png)

## What is JOINS?
- JOIN’s are hard in NoSQL
- SQL Databases are built for JOIN’s.
- A JOIN clause is used to combine rows from two or more tables, based on a related column between them.

```
SELECT Orders.OrderID, Customers.CustomerName, Orders.OrderDate
FROM Orders
INNER JOIN Customers ON Orders.CustomerID=Customers.CustomerID;
```

- **(INNER) JOIN:** Returns records that have matching values in both tables
- **LEFT (OUTER) JOIN:** Returns all records from the left table, and the matched records from the right table
- **RIGHT (OUTER) JOIN:** Returns all records from the right table, and the matched records from the left table
- **FULL (OUTER) JOIN:** Returns all records when there is a match in either left or right table

![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/joins.jpeg)
![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/dbms/4.png)

## Anomalies
An anomaly is a data inconsistency that results from data redundancy and a partial update. For example, each employee in a company has a department associated with them as well as the student group they participate in. 
There are different types of anomalies which can occur in referencing and referenced relation which can be discussed as:
- **Insertion anomaly:** If a tuple is inserted in referencing relation and referencing attribute value is not present in referenced attribute, it will not allow inserting in referencing relation. For Example, If we try to insert a record in STUDENT_COURSE with STUD_NO=7, it will not allow.
    - Let’s say we have a table that has 4 columns. Student ID, Student Name, Student Address and Student Grades. Now when a new student enroll in school, even though first three attributes can be filled but 4th attribute will have NULL value because he doesn't have any marks yet.
- **Deletion and Updation anomaly:** If a tuple is deleted or updated from referenced relation and referenced attribute value is used by referencing attribute in referencing relation, it will not allow deleting the tuple from referenced relation. For Example, If we try to delete a record from STUDENT with STUD_NO =1, it will not allow. To avoid this, following can be used in query:
    - **ON DELETE/UPDATE SET NULL:** If a tuple is deleted or updated from referenced relation and referenced attribute value is used by referencing attribute in referencing relation, it will delete/update the tuple from referenced relation and set the value of referencing attribute to NULL.
    - **ON DELETE/UPDATE CASCADE:** If a tuple is deleted or updated from referenced relation and referenced attribute value is used by referencing attribute in referencing relation, it will delete/update the tuple from referenced relation and referencing relation as well.
- **Update Anomaly:** Let say we have 10 columns in a table out of which 2 are called employee Name and employee address. Now if one employee changes it’s location then we would have to update the table. But the problem is, if the table is not normalized one employee can have multiple entries and while updating all of those entries one of them might get missed.
- **Deletion Anomaly:** This anomaly indicates unnecessary deletion of important information from the table. Let’s say we have student’s information and courses they have taken as follows (student ID,Student Name, Course, address). If any student leaves the school then the entry related to that student will be deleted. However, that deletion will also delete the course information even though course depends upon the school and not the student.

## Normalization & Decompositions
Normalization is the process of splitting relations into well structured relations that allow users to insert, delete, and update tuples without introducing database. Without normalization many problems can occur when trying to load an integrated conceptual model into the DBSM. These problems arise from relations that are generated directly from user views are called anomalies. There are three types of anomalies: update, deletion and insertion anomalies. 
Normalization is the process of minimizing redundancy from a relation or set of relations. Redundancy in relation may cause insertion, deletion and updation anomalies. So, it helps to minimize the redundancy in relations. Normal forms are used to eliminate or reduce redundancy in database tables.

> Attributes that form a candidate key of a relation, i.e. attributes of candidate key, are called prime attributes. And rest of the attributes of the relation are non prime.

Transitive dependency – If `A->B` and `B->C` are two FDs then `A->C` is called transitive dependency.

- **1NF:** The first normal form signifies that each cell of the table must only have single value. Therefore, each intersection of rows and columns must hold atomic values. For example: If we have a column name phone_number than each row for that column must save only single phone number.
    - A relation is in first normal form if every attribute in that relation is **singled valued attribute.**
- **2NF:** We saw candidate key above and here is where it plays a role. 2NF rule signifies that no non-prime attributes in the table are dependent on any of the candidate key. In simple words, If the table is representative of two different entities then it should be broken down into their own entities. For example: If we have a table (Student ID, Student Name, Course Number, Course Name, Teacher ID, Teacher Name) this is representing information about each student enrolled in each course which is taught by each teacher in school. Since it is a representative of three different entities it must be normalized into 2NF form.
    - must be in 1NF
    - A relation is in 2NF if it has No Partial Dependency, i.e., no non-prime attribute (attributes which are not part of any candidate key) is dependent on any proper subset of any candidate key of the table.
    - **Partial Dependency –** If the proper subset of candidate key determines non-prime attribute, it is called partial dependency.
- **3NF:** This rule signifies that tables must be in 2NF form and each table should only contain columns that are non-transitively depended on primary key of their own table. In simple words, if we have a table (Transaction ID, price, quantity, total_sales) here the total sales is the product of price and quantity (price*quantity). Hence sales is transitively depended in Transaction ID which is a primary key here. So each attribute must directly depend upon the primary key.
    - A relation is in third normal form, if there is no transitive dependency for non-prime attributes as well as it is in second normal form.
    - A relation is in 3NF if at least one of the following condition holds in every non-trivial function dependency `X –> Y`
        - `X` is a super key.
        - `Y` is a prime attribute (each element of `Y` is part of some candidate key).

- **Boyce-Codd Normal Form (BCNF) –** A relation R is in BCNF if R is in Third Normal Form and for every FD, LHS is super key. A relation is in BCNF iff in every non-trivial functional dependency X –> Y, X is a super key.

## Transaction Management
A set of logically related operations is known as transaction. The main operations of a transaction are:
- **Read(A):** Read operations `Read(A)` or `R(A)` reads the value of `A` from the database and stores it in a buffer in main memory.
- **Write (A):** Write operation `Write(A)` or `W(A)` writes the value back to the database from buffer. 
    - (Note: It doesn’t always need to write it to database back it just writes the changes to buffer this is the reason where dirty read comes into picture)
- **Commit:** After all instructions of a transaction are successfully executed, the changes made by transaction are made permanent in the database.
- **Rollback:** If a transaction is not able to execute all operations successfully, all the changes made by transaction are undone.
- Transaction in RDBMS follows `ACID` properties, each transactions has these properties.

**What is a Schedule? **
A schedule is a series of operations from one or more transactions. A schedule can be of two types: 
- **Serial Schedule:** When one transaction completely executes before starting another transaction, the schedule is called serial schedule. A serial schedule is always consistent. e.g.; If a schedule S has debit transaction T1 and credit transaction T2, possible serial schedules are T1 followed by `T2 (T1->T2)` or T2 followed by `T1 ((T2->T1)`. A serial schedule has low throughput and less resource utilization.
- **Concurrent Schedule:** When operations of a transaction are interleaved with operations of other transactions of a schedule, the schedule is called Concurrent schedule. e.g.; Schedule of debit and credit transaction shown in Table 1 is concurrent in nature. But concurrency can lead to inconsistency in the database.  The above example of a concurrent schedule is also inconsistent.

![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/dbms/Tt7.png)

## Transaction Isolation Levels in DBMS
As we know that, in order to maintain consistency in a database, it follows ACID properties. Among these four properties (Atomicity, Consistency, Isolation and Durability) Isolation determines how transaction integrity is visible to other users and systems. It means that a transaction should take place in a system in such a way that it is the only transaction that is accessing the resources in a database system.
Isolation levels define the degree to which a transaction must be isolated from the data modifications made by any other transaction in the database system. A transaction isolation level is defined by the following phenomena –
- **Dirty Read** – A Dirty read is the situation when a transaction reads a data that has not yet been committed. For example, Let’s say transaction 1 updates a row and leaves it uncommitted, meanwhile, Transaction 2 reads the updated row. If transaction 1 rolls back the change, transaction 2 will have read data that is considered never to have existed.
- **Non Repeatable read** – Non Repeatable read occurs when a transaction reads same row twice, and get a different value each time. For example, suppose transaction T1 reads data. Due to concurrency, another transaction T2 updates the same data and commit, Now if transaction T1 rereads the same data, it will retrieve a different value.
- **Phantom Read** – Phantom Read occurs when two same queries are executed, but the rows retrieved by the two, are different. For example, suppose transaction T1 retrieves a set of rows that satisfy some search criteria. Now, Transaction T2 generates some new rows that match the search criteria for transaction T1. If transaction T1 re-executes the statement that reads the rows, it gets a different set of rows this time.

Based on these phenomena, The SQL standard defines four isolation levels :
- **Read Uncommitted** – Read Uncommitted is the lowest isolation level. In this level, one transaction may read not yet committed changes made by other transaction, thereby allowing dirty reads. In this level, transactions are not isolated from each other.
- **Read Committed** – This isolation level guarantees that any data read is committed at the moment it is read. Thus it does not allows dirty read. The transaction holds a read or write lock on the current row, and thus prevent other transactions from reading, updating or deleting it.
- **Repeatable Read** – This is the most restrictive isolation level. The transaction holds read locks on all rows it references and writes locks on all rows it inserts, updates, or deletes. Since other transaction cannot read, update or delete these rows, consequently it avoids non-repeatable read.
- **Serializable** – This is the Highest isolation level. A serializable execution is guaranteed to be serializable. Serializable execution is defined to be an execution of operations in which concurrently executing transactions appears to be serially executing.

When which error occures

![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/dbms/isolation.png)

## Concurrency in DBMS
**Concurrency problems in DBMS Transactions**
- When multiple transactions execute concurrently in an uncontrolled or unrestricted manner, then it might lead to several problems. These problems are commonly referred to as concurrency problems in database environment. The five concurrency problems that can occur in database are:
    - **Temporary Update Problem/dirty read problem** - Temporary update or dirty read problem occurs when one transaction updates an item and fails. But the updated item is used by another transaction before the item is changed or reverted back to its last value.
    - **Incorrect Summary Problem** - Consider a situation, where one transaction is applying the aggregate function on some records while another transaction is updating these records. The aggregate function may calculate some values before the values have been updated and others after they are updated.
    - **Lost Update Problem** - In the lost update problem, update done to a data item by a transaction is lost as it is overwritten by the update done by another transaction.
    - **Unrepeatable Read Problem** - The unrepeatable problem occurs when two or more read operations of the same transaction read different values of the same variable.
    - **Phantom Read Problem** - The phantom read problem occurs when a transaction reads a variable once but when it tries to read that same variable again, an error occurs saying that the variable does not exist.

![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/dbms/schedules.jpg)

![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/dbms/tos.png)

More read: https://www.geeksforgeeks.org/types-of-schedules-in-dbms/

**Concurrency-control protocols:** allow concurrent schedules, but ensure that the schedules are conflict/view serializable, and are recoverable and maybe even cascadeless.
These protocols do not examine the precedence graph as it is being created, instead a protocol imposes a discipline that avoids non-seralizable schedules.
Different concurrency control protocols provide different advantages between the amount of concurrency they allow and the amount of overhead that they impose.

**Different categories of protocols:**
- Lock Based Protocol
    - Basic 2-PL
    - Conservative 2-PL
    - Strict 2-PL
    - Rigorous 2-PL
- Graph Based Protocol (precedence graph)
- Time-Stamp Ordering Protocol
- Multiple Granularity Protocol
- Multi-version Protocol

**Lock Based Protocols –**
A lock is a variable associated with a data item that describes a status of data item with respect to possible operation that can be applied to it. They synchronize the access by concurrent transactions to the database items. It is required in this protocol that all the data items must be accessed in a mutually exclusive manner. Let me introduce you to two common locks which are used and some terminology followed in this protocol.
- Shared Lock (S): also known as Read-only lock. As the name suggests it can be shared between transactions because while holding this lock the transaction does not have the permission to update data on the data item. S-lock is requested using lock-S instruction.
- Exclusive Lock (X): Data item can be both read as well as written.This is Exclusive and cannot be held simultaneously on the same data item. X-lock is requested using lock-X instruction.

## Serializability
As discussed in Concurrency control, serial schedules have less resource utilization and low throughput. To improve it, two or more transactions are run concurrently. But concurrency of transactions may lead to inconsistency in database. To avoid this, we need to check whether these concurrent schedules are serializable or not.

**Conflict Serializable:** A schedule is called conflict serializable if it can be transformed into a serial schedule by swapping non-conflicting operations.

**Conflicting operations:** Two operations are said to be conflicting if all conditions satisfy: 
- They belong to different transactions
- They operate on the same data item
- At Least one of them is a write operation

Example:
- Conflicting operations pair (R1(A), W2(A)) because they belong to two different transactions on same data item A and one of them is write operation.
- Similarly, (W1(A), W2(A)) and (W1(A), R2(A)) pairs are also conflicting.
- On the other hand, (R1(A), W2(B)) pair is non-conflicting because they operate on different data item.
- Similarly, ((W1(A), W2(B)) pair is non-conflicting.

**Conflict Equivalent:** Two schedules are said to be conflict equivalent when one can be transformed to another by swapping non-conflicting operations. 

**Can use Precedence graph to test conflict serializability**
- If the graph is cyclic, we can conclude that it is not conflict serializable to any schedule serial schedule.
- If the graph is not cyclic, we can conclude that it is conflict serializable to any schedule serial schedule.

## Recoverability/Recovery
Basically, whenever a transaction is submitted to a DBMS for execution, the operating system is responsible for making sure or to be confirmed that all the operation which need to be in performed in the transaction have completed successfully and their effect is either recorded in the database or the transaction doesn’t affect the database or any other transactions.

**Types of failures –**
There are basically following types of failures that may occur and leads to failure of the transaction such as:
- Transaction failure
- System failure
- Media failure and so on.

**Recovering Techniques**
Recovery techniques are heavily dependent upon the existence of a special file known as a system log. It contains information about the start and end of each transaction and any updates which occur in the transaction. The log keeps track of all transaction operations that affect the values of database items. This information is needed to recover from transaction failure.

**Recovery process:**
- Undoing
- Deferred update
- Immediate update
- Caching/Buffering
- Shadow paging 
