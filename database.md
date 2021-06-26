# Database

| Topic | Article |
| :--: | :--: |
| ETL | [Read Here](https://cofounderstown.com/etls-why-use-cd2f4) |

## DBMS Notes

#### What is DBMS
A database is a collection of information that is organized so that it can be easily accessed, managed and updated. Computer databases typically contain aggregations of data records or files, containing information about sales transactions or interactions with specific customers.
#### DBMS V/S File System
![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/dbms/1.png)
![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/dbms/2.png)

#### SQL vs NoSQL
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

### OLAP V/S OLTP
**OLTP** (It is an online transactional system and manages database modification.), SQL DB prefer
**OLAP** (It is an online data retrieving and data analysis system.), NoSQL

### ACID Properties
A transaction is a single logical unit of work which accesses and possibly modifies the contents of a database. Transactions access data using read and write operations.
In order to maintain consistency in a database, before and after the transaction, certain properties are followed. These are called ACID properties.

- **Atomicity:** By this, we mean that either the entire transaction takes place at once or doesn’t happen at all. There is no midway i.e. transactions do not occur partially. Each transaction is considered as one unit and either runs to completion or is not executed at all. It involves the following two operations.
Abort: If a transaction aborts, changes made to the database are not visible.
Commit: If a transaction commits, changes made are visible.
Atomicity is also known as the ‘All or nothing rule’.

- **Consistency:** This means that integrity constraints must be maintained so that the database is consistent before and after the transaction. It refers to the correctness of a database.
- **Isolation:** This property ensures that multiple transactions can occur concurrently without leading to the inconsistency of database state. Transactions occur independently without interference. Changes occurring in a particular transaction will not be visible to any other transaction until that particular change in that transaction is written to memory or has been committed. This property ensures that the execution of transactions concurrently will result in a state that is equivalent to a state achieved if these were executed serially in some order. (Concurrently Serializable).
- **Durability:** This property ensures that once the transaction has completed execution, the updates and modifications to the database are stored in and written to disk and they persist even if a system failure occurs. These updates now become permanent and are stored in non-volatile memory. The effects of the transaction, thus, are never lost.

### Data Abstraction
**Data Abstraction** refers to the process of hiding irrelevant details from the user. So, what is the meaning of irrelevant details. For eg different website views for different users like admin, student and faculty. 
- There are mainly three levels of data abstraction and we divide it into three levels in order to achieve Data Independence. Data Independence means users and data should not directly interact with each other.
- Three levels of data abstraction:
    - View Level:- Different view for different users like marks and attendance for students but different for faculty.
    - Conceptual Level (Logical):- This level tells how the data is actually stored and structured. We have different data models by which we can store the data
    - Physical Level (Internal):- As the name suggests, the Physical level tells us where the data is actually stored i.e. it tells the actual location of the data that is being stored by the user. The Database Administrators(DBA) decide which data should be kept at which particular disk drive, how the data has to be fragmented, where it has to be stored etc. They decide if the data has to be centralized or distributed. Though we see the data in the form of tables at view level the data here is actually stored in the form of files only. It totally depends on the DBA, how he/she manages the database at the physical level.

### Data Model:
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

### Database Language:
- **DDL** – Data Definition Language (CREATE, DROP, ALTER, TRUNCATE, COMMENT, RENAME)
- **DQL** – Data Query Language (SELECT)
- **DML** – Data Manipulation Language (INSERT, UPDATE, DELETE)
- **DCL** – Data Control Language (GRANT, REVOKE)
- **TCL** – Transaction Control Language (COMMIT, ROLLBACK, SAVEPOINT, SET TRANSACTION)

https://www.quora.com/How-does-a-relational-DBMS-internally-store-its-data-In-what-type-of-data-structure-How-does-it-offer-the-rapid-retrieval-without-loading-the-entire-database-into-the-main-memory-I-have-heard-many-DBMS-use-B-trees

> Keys - (Foreign, Primary, Candidate, Alternate, Super, Secondary)

### Database Optimization Techniques:
- SQL Query optimization
- Indexing
- Sharding (JOINS across different shards is an issue, MEMCACHED is good example of consistent hashing)
- Master Slave Architecture (Master -> Slave and slave for writing, lead to consistency issue).
- Better SELECT query, avoid JOINS, etc.
- Query Caching
- Replicas for read queries and copy
- Sending complete data bundles in one go instead of multiple requests.(Condensed the data query in a single data query). -> gives lesser I/O operations.
- Linked list + Sorted array (at database arch level)

### Hashing
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

### Indexing:
- A database index is an important auxiliary data structure helping to speed up data retrieval. The amount of data accessed to execute an SQL query is the main factor contributing to the execution time. The use of well-designed indexes minimizes the volume of accessed data.
- Indexes can be categorized in several ways: its structure (**B-tree, hash table, binary, column-store, full-text, etc.**), whether it’s clustered or not, and whether it’s partitioned (locally, globally, or not at all). Some store entire rows, some store derivative values, other store straight column copies.
- A typical index is implemented using a balanced tree structure. Leaf levels of an index are sorted based on column values. So, when we want to find all rows with a specific value of an indexed column, we are able to quickly locate the first one and read consecutive rows as long as they match the value.
- **Partition V/S Index:** Table partitions are defined by criteria that split a table into mutually exclusive collections of rows. An index is an auxiliary structure designed to speed up the retrieval of rows fulfilling search criteria.
Can use multilevel indexing and clustered indexing for improvement.
B-Tree (Balanced Tree):

### What is JOINS?
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
