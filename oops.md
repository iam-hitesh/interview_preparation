# OOPS Concepts in C++/Python

Object-oriented programming – As the name suggests uses objects in programming. Object-oriented programming aims to implement real-world entities like inheritance, hiding, polymorphism, etc in programming. The main aim of OOP is to bind together the data and the functions that operate on them so that no other part of the code can access this data except that function.

![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/oops/OOPs-Concepts.jpg)

## Class:
The building block of C++ that leads to Object-Oriented programming is a Class. It is a user-defined data type, which holds its own data members and member functions, which can be accessed and used by creating an instance of that class. A class is like a blueprint for an object.
- A Class is a user-defined data-type which has data members and member functions.

## Object:
An Object is an identifiable entity with some characteristics and behaviour. An Object is an instance of a Class. When a class is defined, no memory is allocated but when it is instantiated (i.e. an object is created) memory is allocated.
**When a program is executed the objects interact by sending messages to one another.**

```
class person{
    char name[20];
    int id;
    
    public:
    void getdetails(){
        
    }
};
  
int main(){
   person p1; // p1 is a object 
}
```

## Access specifiers
- Members declared as `public` in a class, can be accessed from anywhere in the program.
- Members declared as `private` in a class, can be accessed only from within the class. They are not allowed to be accessed from any part of code outside the class.
- `Protected:` Protected access modifier is similar to private access modifier in the sense that it can’t be accessed outside of it’s class unless with the help of friend class, the difference is that the class members declared as Protected can be accessed by any subclass(derived class) of that class as well. 

## Encapsulation: 
In normal terms, Encapsulation is defined as wrapping up of data and information under a single unit. In Object-Oriented Programming, Encapsulation is defined as binding together the data and the functions that manipulate them.
Encapsulation also leads to data abstraction or hiding. As using encapsulation also hides the data. In the above example, the data of any of the section like sales, finance or accounts are hidden from any other section.

**Role of access specifiers in encapsulation**
Access specifiers plays an important role in implementing encapsulation in C++. The process of implementing encapsulation can be sub-divided into two steps:
- The data members should be labeled as private using the private access specifiers
- The member function which manipulates the data members should be labeled as public using the public access specifier

```
#include<iostream>
using namespace std;

class Encapsulation{
	private:
		// data hidden from outside world(encapsulation)
		int x;
		
	public:
		void set(int a){
			x = a;
		}
		
		int get(){
			return x;
		}
};

int main(){
	Encapsulation obj;
	
	obj.set(5);
	
	cout<<obj.get();
	return 0;
}
```

## Abstraction: 
Data abstraction is one of the most essential and important features of object-oriented programming in C++. Abstraction means displaying only essential information and hiding the details. Data abstraction refers to providing only essential information about the data to the outside world, hiding the background details or implementation.

Consider a real-life example of a man driving a car. The man only knows that pressing the accelerators will increase the speed of the car or applying brakes will stop the car but he does not know about how on pressing accelerator the speed is actually increasing, he does not know about the inner mechanism of the car or the implementation of accelerator, brakes etc in the car. This is what abstraction is.
- Abstraction using Classes: We can implement Abstraction in C++ using classes. The class helps us to group data members and member functions using available access specifiers. A Class can decide which data member will be visible to the outside world and which is not.
- Abstraction in Header files: One more type of abstraction in C++ can be header files. For example, consider the pow() method present in math.h header file. Whenever we need to calculate the power of a number, we simply call the function pow() present in the math.h header file and pass the numbers as arguments without knowing the underlying algorithm according to which the function is actually calculating the power of numbers.

**Advantages of Data Abstraction:**
- Helps the user to avoid writing the low level code
- Avoids code duplication and increases reusability.
- Can change internal implementation of class independently without affecting the user.
- Helps to increase security of an application or program as only important details are provided to the user.

```
#include <iostream>
using namespace std;

class implementAbstraction {
	private:
		int a, b;
		
	public:
		void set(int x, int y){
			a = x;
			b = y;
		}
		
		void display(){
			cout<<"a = " <<a << endl;
			cout<<"b = " << b << endl;
		}
};

int main(){
	implementAbstraction obj;
	obj.set(10, 20);
	obj.display();
	return 0;
}
```

## Polymorphism: 
The word polymorphism means having many forms. In simple words, we can define polymorphism as the ability of a message to be displayed in more than one form.

A person at the same time can have different characteristic. Like a man at the same time is a father, a husband, an employee. So the same person posses different behaviour in different situations. This is called polymorphism.

An operation may exhibit different behaviours in different instances. The behaviour depends upon the types of data used in the operation.

C++ supports operator overloading and function overloading.
- Operator Overloading: The process of making an operator to exhibit different behaviours in different instances is known as operator overloading.
- Function Overloading: Function overloading is using a single function name to perform different types of tasks.
- Polymorphism is extensively used in implementing inheritance.

In C++ polymorphism is mainly divided into two types:
- Compile time Polymorphism
    - **Function overloading** - When there are multiple functions with same name but different parameters then these functions are said to be overloaded. Functions can be overloaded by change in number of arguments or/and change in type of arguments.
        ```
        void func(int x){
            cout << "value of x is " << x << endl;
        }
      
        // function with same name but 1 double parameter
        void func(double x){
            cout << "value of x is " << x << endl;
        }
        ```
    - operator overloading
- Runtime Polymorphism
    - Virtual functions

## Inheritance:
The capability of a class to derive properties and characteristics from another class is called Inheritance. Inheritance is one of the most important features of Object-Oriented Programming.

- **Sub Class:** The class that inherits properties from another class is called Sub class or Derived Class.
- **Super Class:** The class whose properties are inherited by sub class is called Base Class or Super class.
- **Reusability:** Inheritance supports the concept of “reusability”, i.e. when we want to create a new class and there is already a class that includes some of the code that we want, we can derive our new class from the existing class. By doing this, we are reusing the fields and methods of the existing class.

**Modes of Inheritance**
- **Public mode:** If we derive a sub class from a public base class. Then the public member of the base class will become public in the derived class and protected members of the base class will become protected in derived class.
- **Protected mode:** If we derive a sub class from a Protected base class. Then both public member and protected members of the base class will become protected in derived class.
- **Private mode:** If we derive a sub class from a Private base class. Then both public member and protected members of the base class will become Private in derived class. 

```
// C++ Implementation to show that a derived class
// doesn’t inherit access to private data members.
// However, it does inherit a full parent object
class A{
    public:
	    int x;
    protected:
	    int y;
    private:
	    int z;
};

class B : public A{
	// x is public
	// y is protected
	// z is not accessible from B
};

class C : protected A{
	// x is protected
	// y is protected
	// z is not accessible from C
};

// 'private' is default for classes
class D : private A {
	// x is private
	// y is private
	// z is not accessible from D
};
```

## Dynamic Binding:
In dynamic binding, the code to be executed in response to function call is decided at runtime. C++ has virtual functions to support this.

## Message Passing:
Objects communicate with one another by sending and receiving information to each other. A message for an object is a request for execution of a procedure and therefore will invoke a function in the receiving object that generates the desired results. Message passing involves specifying the name of the object, the name of the function and the information to be sent.


## Constructor & Destructor
**Constructor**
A constructor is a member function of a class that has the same name as the class name. It helps to initialize the object of a class. It can either accept the arguments or not. It is used to allocate the memory to an object of the class. It is called whenever an instance of the class is created. It can be defined manually with arguments or without arguments. There can be many constructors in class. It can be overloaded but it can not be inherited or virtual. There is a concept of copy constructor which is used to initialize a object from another object. 

**Destructor**
Like constructor, deconstructor is also a member function of a class that has the same name as the class name preceded by a tilde(~) operator. It helps to deallocate the memory of an object. It is called while object of the class is freed or deleted. In a class, there is always a single destructor without any parameters so it can’t be oveloaded. It is always called in the reverse order of the constructor. if a class is inherited by another class and both the classes have a destructor then the destructor of the child class is called first, followed by the destructor of the parent or base class. 

```
class Z{
    public:
        // constructor
        Z(){
            cout<<"Constructor called"<<endl;
        }

        // destructor
        ~Z(){
            cout<<"Destructor called"<<endl;
        }
};
```


## Examples in different Programming languages
```
# parent class
class Bird:
    def __init__(self):
        // constructor
        print("Bird is ready")

    def whoisThis(self):
        print("Bird")

    def swim(self):
        print("Swim faster")

# child class
class Penguin(Bird):
    def __init__(self):
        # call super() function
        super().__init__()
        print("Penguin is ready")
        
        self.name = 'Penguin'
        
        # Private attribute specify by _ or __
        self.__type = 'Bird'

    def whoisThis(self):
        print("Penguin")

    def run(self):
        print("Run faster")

peggy = Penguin()
peggy.whoisThis()
peggy.swim()
peggy.run()
```


## Low level design example of consistent hashing
```
package algorithms;

import models.Node;
import models.Request;

import java.util.List;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ConcurrentSkipListMap;
import java.util.concurrent.CopyOnWriteArrayList;
import java.util.function.Function;

public class ConsistentHashing implements Router {
    private final Map<Node, List<Long>> nodePositions;
    private final ConcurrentSkipListMap<Long, Node> nodeMappings;
    private final Function<String, Long> hashFunction;
    private final int pointMultiplier;


    public ConsistentHashing(final Function<String, Long> hashFunction,
                             final int pointMultiplier) {
        if (pointMultiplier == 0) {
            throw new IllegalArgumentException();
        }
        this.pointMultiplier = pointMultiplier;
        this.hashFunction = hashFunction;
        this.nodePositions = new ConcurrentHashMap<>();
        this.nodeMappings = new ConcurrentSkipListMap<>();
    }

    public void addNode(Node node) {
        nodePositions.put(node, new CopyOnWriteArrayList<>());
        for (int i = 0; i < pointMultiplier; i++) {
            for (int j = 0; j < node.getWeight(); j++) {
                final var point = hashFunction.apply((i * pointMultiplier + j) + node.getId());
                nodePositions.get(node).add(point);
                nodeMappings.put(point, node);
            }
        }
    }

    public void removeNode(Node node) {
        for (final Long point : nodePositions.remove(node)) {
            nodeMappings.remove(point);
        }
    }

    public Node getAssignedNode(Request request) {
        final var key = hashFunction.apply(request.getId());
        final var entry = nodeMappings.higherEntry(key);
        if (entry == null) {
            return nodeMappings.firstEntry().getValue();
        } else {
            return entry.getValue();
        }
    }
}
```

