# JavaScript Notes

##### 1.) JavaScript Engine setup
![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/js/execution-context.png)
##### 2.) Execution Context
An execution context is nothing but an environment where the Javascript code is evaluated and executed. Whenever any code is run in JavaScript, it’s run inside an execution context.
![Alt Text](https://github.com/iam-hitesh/interview_preparation/raw/main/images/js/execution-context-2.png)
**There are 3 different types of execution context in JavaScript:**
- **Global Execution Context (GEC)**
    - This is the default or base execution context. The code that is not inside any function is in the global execution context. It performs two things: it creates a global object which is a window object (in the case of browsers) and sets the value of _this_ to equal to the global object(window object). There can only be one global execution context in a program.
    - ```this === window -> true```
- **Function Execution Context (FEC)**
    - Every time a function is invoked, an execution context is created for that function. The execution context is destroyed when the associated function has returned or execution is over. Each function has its own execution context, but it’s created when the function is invoked or called.
- **Eval Execution Context (EEC)**
    - code inside an `eval` function also has its own execution context. But since it is now deprecated & also not recommended, we shall not discuss it.

```
/* global execution context */

// every execution context has it's own variable environment
// GEC: global execution context
// FEC: function execution context

function baz(){
   // FEC of baz
   var foo = 3;
   console.log(foo); //3
}

function bar(){
   // FEC of bar
   var foo = 2;
   console.log(foo); //2
   baz();
}

var foo = 1; //GEC
console.log(foo); //1
bar();
console.log(foo); //1

/* global execution context */
```
![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/js/gec-phase.png)
- When the program runs, the first thing the javascript engine creates is a global execution context. Everything that is not inside a function is a part of the GEC. So the var foo is in the GEC & is put into memory space.
- When the javascript interpreter comes across bar(),the function is invoked, a new execution context is immediately created and everything inside of it starts executing.
- Now this is the most important point to remember: 'Every execution context (FEC) has it's own variable environment'. Therefore when the variable foo is declared again with value 2, it is created only within bar()'s execution context.
- Then again baz() is invoked, and a new execution context with its own variable environment, it's own memory space for its variables is created. Hence, when the variable foo is re-declared in baz(), it is only limited to this environment, and is different altogether.
- In short, every time you call a function, you get your own execution context.
- So even though, foo is declared 3 times, they are distinct, they are unique, they don't touch each other.
- Therefore calling functions bar() and baz() wouldn't affect foo = 1 in the GEC. To prove that, we have consoled foo again at the very end of the program after calling bar(). Should it have an impact? The answer is NO!!.

##### 3.)  Execution Stack
In computer science, a call stack is a stack data structure that stores information about the active subroutines of a computer program. This kind of stack is also known as an execution stack, program stack, control stack, run-time stack, or machine stack, and is often shortened to just "the stack".
A subroutine in simple words is nothing but what we call a function. Simply put, JavaScript has a single call stack in which it keeps track of what function we are currently executing & what function is to be executed after that. But first- what's a stack? A stack is an array-like data structure where you can add items(push) to the back and only remove(pop) the last item from it. 

**Call stack  filling**
Initially, before running any piece of javascript code, the execution stack is empty. When we run a javascript program/file, the javascript engine creates a global execution context and pushes it on top of the stack the moment your program starts executing. 
> In simple words, it is the context of your entire javascript program/source code or the context within which your entire code runs(as shown in the code snippet).

![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/js/call-stack-following.png)

**The GEC remains on the stack and is eventually popped off when the program completely finishes executing.**

##### 4.) Scope Chain
**What is Scope?**
Scope in JavaScript refers to the accessibility or visibility of variables. That is, which parts of a program have access to the variable or where the variable is visible. Scoping is determining where variables, functions, and objects are accessible in your code during runtime.
- Global Scope
- Local/Function Scope
- Block Scope (`var` is not block scoped)

**Only let and const are block scoped**
**`var` is not block scoped**

**Scope Chain**
What if, an execution context has no definition of a variable which it wants to print? Consider the code snippet below. baz() has no variable declared as foo in its execution context.
When a variable is used in JavaScript, the JavaScript engine will try to find the variable’s value in the current scope. If it could not find the variable, it will look into the outer scope and will continue to do so until it finds the variable or reaches global scope.
> 'Every execution context has a reference to it's outer environment', all the way up to the global scope. This hierarchy/chain of reference is what is termed as Scope Chain.

##### 5.) Hoisting

```
console.log(x) => undefined

var x = 10;

console.log(y) => ReferenceError:

let y = 10;

// Block scoped
if (true) {
    var z = 10;
}

console.log(z) => 10

var a = 30;
var a = 40;

if (true) {
  var a = 20;
}

console.log(a) => 20

// function is local scoped

let c = 30;

if (true) {
  let c = 20;
}

console.log(c) => 30

function bar() {
    console.log(b);
    console.log(d);
}

var b = 10;
bar(); // 10, undefined
var d = 20;

console.log(cd()); // c is not a function

var cd = function () {
  console.log("THIS IS WORLD")
}

console.log(cd()); // THIS IS WORLD
```
> Hoisting is a phenomenon in JavaScript by which we can access the variables and functions even before we have initialised/declared in the code, due to the memory allocated to the function and variables during creation phase itseld in Global Execution context.

**What is lexical environment**
Every time the JavaScript engine creates an execution context to execute the function or global code, it also creates a new lexical environment to store the variable defined in that function during the execution of that function. A lexical environment is a data structure that holds identifier-variable mapping.
`Whenever an execution context is created, an lexical environment also created.`
Lexical environment is basically local memory along with the lexical enivornment of its parents.

##### 6.) let, const and var
All declarations (var, let, const, function, function*, class) are "hoisted" in JavaScript. This means that if a name is declared in a scope, in that scope the identifier will always reference that particular variable.

The difference between var/function/function* declarations and let/const/class declarations is the initialisation.
The former are initialised with undefined or the (generator) function right when the binding is created at the top of the scope. The lexically declared variables however stay uninitialised. This means that a ReferenceError exception is thrown when you try to access it. It will only get initialised when the let/const/class statement is evaluated, everything before (above) that is called the **`temporal dead zone`**.

- ReferenceError - When we cannot access the var, let and const, temporal dead zone in let and const.
- SyntaxError - in case of redecalartion of let and const
- TypeError -  in case of redefined or assign value again to const

##### 7.) BLOCK Scope for let and const
**What is block?**
Compound statement, where we group the multiple statment into one using block.
```
{
    //This is block
}

if (true) {
    this is block
}

if (true) {
    var x = 10;
    let y = 20;
}

console.log(x) => 10
console.log(y) => ReferenceError
```

**What is shadowing**
Shadowing is when value of a variable is shadowed by other same name decalared variable in same or different scope.

##### 8.) Closures
Function along with its lexical scope forms a closure.
A closure is the combination of a function bundled together (enclosed) with references to its surrounding state (the lexical environment). In other words, a closure gives you access to an outer function’s scope from an inner function. In JavaScript, closures are created every time a function is created, at function creation time.

**Uses of Closures**
- Module design pattern
- Currying
- Functions like once
- memoize (High Order function)
- maintaining state in async world
- setTimeouts
- Iterators
- and many more.....

**Pros**
- Data Encapsulation & security
- function constructor

**cons**
- Overusage of memory sometime
- Not garbage collected variables till the program expires, can lead to memory leaks if not handled properly.

> Garbage collector is a program in JavaScript engine or browser, which frees up the un utilised memory.

```
function makeFunc() {
  var name = 'Mozilla';
  
  function displayName() {
    alert(name);
  }
  
  displayName();
}

var myFunc = makeFunc();
```
```
function makeFunc() {
  var name = 'Mozilla';
  function displayName() {
    alert(name);
  }
  return displayName;
}

var myFunc = makeFunc();
myFunc();
```
```
function a(){
    var x = 10;
    function y () {
        console.log(x)
    }

    x = 200;

    return y;
}

console.log(a()()); // 200
```
```
function x () {
    var a = 100;
    function y (){
        var b = 10;
        
        function x () {
            console.log(a, b)
        }
        
        x();
    }
    
    y();
}

z();
```
```
function a(){
    return function(b) {
        return b;
    }
}
```

```
function counter() {
  let count = 0;
  
  return function increment() {
    count++;
    console.log(count);
  }
}

var count = counter();
count(); \\ 1
count(); \\ 2
count(); \\ 3

var count2 = counter();
count2(); \\ 1
count2(); \\ 2
count2(); \\ 3
```

**This is example of function constructor**
> Need to use new keyword to call function;

```
function counter() {
  let count = 0;
  
  this.increment = function () {
    count++;
    
    return count;
  }
  
  this.decrement = function () {
    count--;
    
    return count;
  }
}

var count = new counter();
console.log(count.increment()); // 1
console.log(count.increment()); // 2
console.log(count.increment()); // 3
console.log(count.decrement()); // 2
console.log(count.decrement()); // 1

var count2 = new counter();
console.log(count2.increment()); // 1
console.log(count2.increment()); // 2
console.log(count2.increment()); // 3
console.log(count2.decrement()); // 2
console.log(count2.decrement()); // 1
```

**Famous interview problem**

![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/js/sum-recursion-problem.png)

##### 9.) Immediately Invoked Function Expressions (IIFE)
- **Immediately Invoked**: This part is easy to explain and demonstrate. This type of function is called immediately invoked as these functions are executed as soon as they are mounted to the stack, it requires no explicit call to invoke the function. If we look at the syntax itself we have two pairs of closed parentheses, the first one contains the logic to be executed and the second one is generally what we include when we invoke a function, the second parenthesis is responsible to tell the compiler that the function expression has to be executed immediately.
- **Function Expressions**: It is simple to understand that a Function Expression is a Function that is used as an expression. JavaScript lets us use Functions as Function Expression if we Assign the Function to a variable, wrap the Function within parentheses or put a logical not in front of a function. The following program illustrates the different ways we can create a Function Expression.
- IIFEs have there own scope i.e. the variables you declare in the Function Expression will not be available outside the function.
```
(function() { return "Return something"; })();
(function() { console.log("Function called!"); })();
```
![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/js/iife.png)

##### 10.) Anonymous functions
- Anonymous Function is a function that does not have any name associated with it. Normally we use the function keyword before the function name to define a function in JavaScript, however, in anonymous functions in JavaScript, we use only the function keyword without the function name.
- An anonymous function is not accessible after its initial creation, it can only be accessed by a variable it is stored in as a function as a value. An anonymous function can also have multiple arguments, but only one expression.

```
function() {
    // Function Body
}

var greet = function (platform) {
    console.log("Welcome to ", platform);
};

setTimeout(function () {
    console.log("Hello World!");
}, 2000);
```

##### 11.) More on Functions
- **First class functions**
  - The ability to use functions as values is known as first class functions.
  - A programming language is said to have First-class functions if functions in that language are treated like other variables. So the functions can be assigned to any other variable or passed as an argument or can be returned by another function.
  - JavaScript treat function as a first-class-citizens. This means that functions are simply a value and are just another type of object.
- **Function Statement === Function decalartion**
  ```
  a(); // Hello World
  function a() {
      // This is function statement
      console.log("Hello World")
  }
  a(); // Hello World
  ```
- **Function expression**
  As we are defining it to a variable so it is hoisted
  ```
  b(); // TypeError: b is not a function, because it is a variable till here
  var b = function (){
      // This is function expression
      console.log("Hello World")
  }
  b(); // Hello World
  ```
- **Named Function expression**
  As we are defining it to a variable so it is hoisted
  ```
  b(); // TypeError: b is not a function, because it is a variable till here
  var b = function xyz (parameters){
      // This is function expression
      console.log("Hello World")
      console.log(xyz) // [Function: xyz]
  }
  b(arguments); // Hello World
  xyz(); // ReferenceError: xyz is not defined
  ```

- **Arrow functions**
  ```
  const a = () => {
      // This is arrow functions
  }
  ```
  
- **Higher Order Functions**
    - A higher order function is a function that takes a function as an argument, or returns a function. Higher order function is in contrast to first order functions, which don’t take a function as an argument or return a function as output.
    - Example of `.map()` and `.filter()`. Both of them take a function as an argument. They're both higher order functions.
    - Functions that operate on other functions, either by taking them as arguments or by returning them, are called higher-order functions. Since we have already seen that functions are regular values, there is nothing particularly remarkable about the fact that such functions exist. The term comes from mathematics, where the distinction between functions and other values is taken more seriously.
    - Higher-order functions allow us to abstract over actions, not just values. They come in several forms. For example, we can have functions that create new functions.
    - In the context of programming, these kinds of vocabularies are usually called abstractions. Abstractions hide details and give us the ability to talk about problems at a higher (or more abstract) level.
        ```
        function x(){
            // First order function
        }
        
        function y(x) {
            // y is higher order function
            x();
        }
        ```
        
##### 12.) Pure functions
Pure Function is a function (a block of code ) that always returns the same result if the same arguments are passed. It does not depend on any state, or data change during a program’s execution rather it only depends on its input arguments.
Also a pure function does not produce any observable side effects such as network requests or data mutation etc.

Let’s see the below JavaScript Function:
```
function calculateGST( productPrice ) {
    return productPrice * 0.05;
}
```

Now, let’s see one more function below:
```
var tax = 20;
function calculateGST( productPrice ) {
    return productPrice * (tax / 100) + productPrice;
}
```

Note: If a pure function calls a pure function, this isn’t a side effect and the calling function is still considered as pure. (Example: using Math.max() inside a function)

Below are the some side effects (but not limited to) which a function should not produce in order to be considered as a pure function –

- Making a HTTP request
- Mutating data
- Printing to a screen or console
- DOM Query/Manipulation
- Math.random()
- Getting the current time

##### 13.) setTimeout

```
function x (){
    for (var i = 0;i <= 5; ++i) {
        setTimeout(function () {
            console.log(i);
        }, i * 1000);
    }
}
x();

Output:
6
6
6
6
6
6
```
**Both below functions are same, one is IIFE(Immediately invoked function expression)**
```
function x (){
    for (var i = 0;i <= 5; ++i) {
        (function (x) {
            setTimeout(function () {
                console.log(x);
            }, x * 1000);
        })(i);
    }
}

function x (){
    for (var i = 0;i <= 5; ++i) {
        function close(x) {
            setTimeout(function (x) {
                console.log(x);
            }, x * 1000);
        }
        
        close(i);
    }
}
x();

Output:
0
1
2
3
4
5
```

```
function x (){
    for (let i = 0;i <= 5; ++i) {
        setTimeout(function () {
            console.log(i);
        }, i * 1000);
    }
}
x();

Output:
0
1
2
3
4
5
```

##### 14.) Callback functions
- **What is callback function**
  When we pass a function as argument in another function, then that argument function is known as callback function.
  ```
  function a(){
      
  }
  
  function b(a){
   // Here a is callback function   
  }
  
  setTimeout(function (){
      // This is callback function
  }, 5000);
  
  function attachEventListner() {
     let count = 0;
      document.getElementById('clicked').addEventListener('click', function() {
        ++count;
      });
  }
  attachEventListner();
  ```
  
** event listeners are heavy need to remove to free up the memory, using garbage collection.
  
#### 15.) setTimeout & setInterval & setImmediate & process.nextTick
**The setTimeout() and setInterval() are both methods of the HTML DOM Window object.**

- The `setTimeout(fn, delay)` executes after a given interval.
- The `setInterval(fn, delay)` method repeats a given function at every given time-interval.
- `setImmediate(fn)` callbacks are called after I/O Queue callbacks are finished or timed out. setImmediate callbacks are placed in Check Queue, which are processed after I/O Queue.
- The first one executed was process.nextTick, which puts its callback at the front of the event queue. It will execute after the code currently being executed but before any I/O events or timers.
- execution sequence `nextTick -> setTimeout (if timeout is 0) -> setImmediate`
- Finally, we have setImmediate, which is clearly not as immediate as its name suggests! Its callback is placed in the check queue of the next cycle of the event loop. Since the check queue occurs later than the timer queue, setImmediate will be slower than setTimeout 0.


- `clearTimeout(timeoutId)` to clear timeout;
- `clearInterval(intervalId)` to clear interval;

All in all, the event loop looks like this:

timers -> IO -> poll -> check ->close -> timers -> ...

**Timers:** callbacks from setInterval or setTimeout
**IO callbacks:** callbacks from I/O events
**Idle:** used internally by Node between IO and Poll phases
**Poll:** retrieve new I/O events
**Check:** callbacks from setImmediate execute here
**Close:** handle closed connections like sockets
```
setTimeout(function() {
  console.log('setTimeout')
}, 0);

setInterval(function() {
  console.log('setInteval')
}, 1000);

setImmediate(function() {
  console.log('setImmediate')
});

let racer1 = function() {
  setTimeout(() => console.log("timeout"), 0);
  setImmediate(() => console.log("immediate"));
  process.nextTick(() => console.log("nextTick"));
}

let racer2 = function() {
  process.nextTick(() => console.log("nextTick"));
  setTimeout(() => console.log("timeout"), 0);
  setImmediate(() => console.log("immediate"));
}

let racer3 = function() {
  setImmediate(() => console.log("immediate"));
  process.nextTick(() => console.log("nextTick"));
  setTimeout(() => console.log("timeout"), 0);
}

racer1()
racer2()
racer3()

Output:
nextTick
nextTick
nextTick
timeout
timeout
timeout
immediate
immediate
immediate
```

#### 16.) Event Loop
>**Definition**: As we know event loop is a mechanism provided by javascript run-time environment to handle the execution of code chunks using JS engine.

- JavaScript is a synchronous single-threaded programming language and has a single call stack to perform all tasks.
- It can execute a single code at a time using call stack.
- The event loop allows JavaScript to perform non-blocking I/O operations despite the fact that JavaScript is single-threaded. It is done by assigning operations to the operating system whenever and wherever possible.


**Features of Event Loop:**
- Event loop is an endless loop, which waits for tasks, executes them and then sleeps until it receives more tasks.
- The event loop executes tasks from the event queue only when the call stack is empty i.e. there is no ongoing task.
- The event loop allows us to use callbacks and promises.
- The event loop executes the tasks starting from the oldest first.

![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/js/event-loop-1.png)
![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/js/event-loop-2.png)

> When using Node.js, a special library module called libuv is used to perform async operations. This library is also used, together with the back logic of Node, to manage a special thread pool called the libuv thread pool.This thread pool is composed of four threads used to delegate operations that are too heavy for the event loop. I/O operations, Opening and closing connections, setTimeouts are the example of such operations.
> Luckily, the browser gives us some features that the JavaScript engine itself doesn’t provide: a Web API. This includes the DOM API, setTimeout, HTTP requests, and so on. This can help us create some async, non-blocking behavior 🚀

**Eg. First setTimeout goes to call Stack, call stack send callback function to web api and set a timer, then after timer finished it goes to queue and then when call stack is get empty it will go to call stack to get executed.**

**A good read https://dev.to/lydiahallie/javascript-visualized-event-loop-3dif**

**Phases of the Event loop:**

![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/js/phase-of-event-loop.png)

- **Timers:** Callbacks scheduled by setTimeout() or setInterval() are executed in this phase.
- **Pending Callbacks:** I/O callbacks deferred to the next loop iteration are executed here.
- **Idle, Prepare:** Used internally only.
- **Poll:** Retrieves new I/O events.
- **Check:** It invokes setIntermediate() callbacks.
- **Close Callbacks:** It handles some close callbacks. Eg: socket.on(‘close’, …)


**Web API's**
- setTimeout
- DOM API's
- fetch()
- localStorage
- console
- location
all these are web api's, we can use all these through this/window in JavaScript.

**Steps in Event loop**
- **Evaluate script**: Synchronously execute the script as though it were a function body. Run until the Call Stack is empty. (This is executed through macro task queue)
- **Run a Task/Macro Task Queue:** Select the oldest Task from the Task Queue. Run it until the Call Stack is empty.
- **Run all microtasks/(Micro queue tasks):** Select the oldest Microtask from the Microtask Queue. Run it until the Call Stack is empty. Repeat until the Microtask Queue is empty.
- **Rerender:** Rerender the UI. Then, return to step 2. (This step only applies to browsers, not NodeJS).

#### 17.) Macro & Micro Tasks
Event loop has more than one task queue, one for tasks / macrotasks (terms used interchangeably) and one for microtasks, now the obvious question is how the tasks are identified as one of these type.
As per specs 
- `parser`, `events`, `callbacks`, `resource fetching`, `DOM manipulation`, `setTimeout`, `setInterval` are considered as macrotasks and managed as task queues, scripting parse also done in this task itself.
- Where as `promises`, `mutation observers`, `intersection observers` are considered as microtasks and managed by microtask queue.

- **micro task queue has higher priority**
- **parsing(script executing) -> microtask -> macrotask -> microtask -> macrotask and so on....**
- **how can we enqueue a microtask using the queueMicrotask API and how it is useful.**

![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/js/macro-micro-task.png)

#### 18.) JS Engine
Just In Time Compilation
Ahead of time compilation

- Javascript runtime refers to where your javascript code is executed when you run it. That said, javascript can be executed on google chrome, in which case your javascript runtime is v8, if on mozilla - it is spidermonkey, if IE - then its chakra and if on node, again its v8. 

**Web API's**
The Web APIs are provided by the browser, they live inside the browser's javascript runtime environment but outside the javascript engine. HTTP, AJAX, Geolocation, DOM events and setTimeout are all examples of the web APIs. Let's use a code example to help us figure out how web APIs help us in writing asynchronous code.

**Message Queue**
The message queue is basically a data structure that javascript runtime uses to list messages that need to be processed. Unlike the call stack, the message queue uses the First In First Out(FIFO) principle, The first function added to the queue is processed first.

https://dev.to/lydiahallie/javascript-visualized-the-javascript-engine-4cdf

![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/js/runtime-env.png)

#### 19.) call(), apply() & bind()
- In other object-oriented programming languages, the this keyword always refers to the current instance of the class. Whereas in JavaScript, the value of this depends on how a function is called.
- The call, bind and apply methods is being used to set the this keyword independent of how the function is called. This is especially useful for the callbacks (as in the above example).
- The bind method creates a copy of the function and sets the this keyword, while the call and apply methods sets the this keyword and calls the function immediately.
- call and apply method almost similar but call takes separate arguments and apply takes in the format of array

**fn.bind(object, arg1, arg2)**
![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/bind.png)

**fn.call(object, arg1, arg2)**
![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/call.png)

**fn.apply(object, [arg1, arg2])**
![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/apply.png)

#### 20.) Prototypal Inheritance
JavaScript is a prototype-based, Object Oriented programming language. After the ES6 updates, JavaScript allowed for “prototypal inheritance”, meaning that objects and methods can be shared, extended, and copied.
JavaScript is the most common of the prototype-capable languages, and its capabilities are relatively unique. When used appropriately, prototypical inheritance in JavaScript is a powerful tool that can save hours of coding.
Ever wondered why we can use built-in methods such as .length, .split(), .join() on our strings, arrays, or objects? We never explicitly specified them, where do they come from? Now don't say "It's JavaScript lol no one knows, it's magic 🧚🏻‍♂️", it's actually because of something called prototypal inheritance. It's pretty awesome, and you use it more often than you realize! 

- When we create a constructor function, it wasn't the only object we created. Automatically, we also created another object, called the `prototype!` By default, this object contains a constructor property, which is simply a reference to the original constructor function, Dog in this case.
- In an extended class, we can access the parent class' constructor using the super keyword. The arguments the parent class' constructor expects, we have to pass to super: name in this case. 
- Each and every object has prototype
- Inheriting prototypical properties of another object is known as Prototypal inheritance.

![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/carbon.png)
![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/carbon(1).png)

#### 21.) polyfill for bind() method
**What is polyfill**
A polyfill is a browser fallback, made in JavaScript, that allows functionality you expect to work in modern browsers to work in older browsers, e.g., to support canvas (an HTML5 feature) in older browsers.

![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/polyfill.png)

#### 22.) Generators & Iterators
- Normal functions follow something called a run-to-completion model: when we invoke a function, it will always run until it completes (well, unless there's an error somewhere). We can't just randomly pause a function somewhere in the middle whenever we want to.
- Now here comes the cool part: generator functions don't follow the run-to-completion model! 🤯 Does this mean that we can randomly pause a generator function in the middle of executing it? Well, sort of! Let's take a look at what generator functions are and how we can use them.
- We create a generator function by writing an asterisk * after the function keyword.
- But that's not all we have to do to use generator functions! Generator functions actually work in a completely different way compared to regular functions:
    - Invoking a generator function returns a generator object, which is an iterator.
    - We can use the yield keyword in a generator function to "pause" the execution.
- The generator object contains a `next` method (on the prototype chain). This method is what we'll use to iterate the generator object. However, in order to remember the state of where it previously left off after yielding a value, we need to assign the generator object to a variable. I'll call it genObj short for generatorObject.


- As we just saw, a generator function returns an iterator (the generator object). But.. wait an iterator? Does that mean we can use for of loops, and the spread operator on the returned object? Yas! 🤩
- https://dev.to/lydiahallie/javascript-visualized-generators-and-iterators-e36

#### 23.) Promises & async/await
A promise is an object that may produce a single value some time in the future: either a resolved value, or a reason that it’s not resolved (e.g., a network error occurred). A promise may be in one of 3 possible states: fulfilled, rejected, or pending. Promise users can attach callbacks to handle the fulfilled value or the reason for rejection.

A promise is an object which can be returned synchronously from an asynchronous function. It will be in one of 3 possible states:

- **Fulfilled:** The promise has been resolved. Everything went fine, no errors occurred within the promise 🥳
- **Rejected:** The promise has been rejected. Argh, something went wrong..
- **Pending:** The promise has neither resolved nor rejected (yet), the promise is still pending. 

A promise is settled if it’s not pending (it has been resolved or rejected). Sometimes people use resolved and settled to mean the same thing: not pending.

```
const wait = time => {
    return new Promise((resolve, reject) => {
            setTimeout(resolve, time)
        }
    )
};

wait(3000).then(() => console.log('Hello!')); // 'Hello!'
```

> The result of the .then itself is a promise value. This means that we can chain as many .thens as we want: the result of the previous then callback will be passed as an argument to the next then callback! 

![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/js/promise.png)


- **ES7** introduced a new way to add async behavior in JavaScript and make working with promises easier! With the introduction of the async and await keywords, we can create async functions which implicitly return a promise. But.. how can we do that? 
- Although the fact that async functions implicitly return promises is pretty great, the real power of async functions can be seen when using the await keyword! With the await keyword, we can suspend the asynchronous function while we wait for the awaited value return a resolved promise. If we want to get the value of this resolved promise, like we previously did with the then() callback, we can assign variables to the awaited promise value!

```
const one = () => Promise.resolve('One!');

async function myFunc() {
    console.log('In function earlier!')
    const res = await one();
    console.log(res);
    console.log('In function later!')
}

console.log('Before function!')
myFunc();
console.log('After function!')

// Output:
// Before function!
// In function earlier!
// After function!
// One!
// In function later!
```

- When encountering an await keyword, the async function gets suspended. ✋🏼 The execution of the function body gets paused, and the rest of the async function gets run in a microtask instead of a regular task! 
- Now that the async function myFunc is suspended as it encountered the await keyword, the engine jumps out of the async function and continues executing the code in the execution context in which the async function got called: the global execution context in this case!

#### 24.) async v/s defer
With async, the file gets downloaded asynchronously and then executed as soon as it’s downloaded.

With defer, the file gets downloaded asynchronously, but executed only when the document parsing is completed. With defer, scripts will execute in the same order as they are called. This makes defer the attribute of choice when a script depends on another script. For example, if you’re using jQuery as well as other scripts that depend on it, you’d use defer on them (jQuery included), making sure to call jQuery before the dependent scripts.

A good strategy is to use async when possible, and then defer when async isn’t an option.

👉Note that both attributes don’t have any effect on inline scripts.

![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/async-defer.jpg)

#### 25.) Debouncing vs Throttling
- Debouncing and throttling techniques are used to limit the number of times a function can execute. Generally, how many times or when a function will be executed is decided by the developer. But in some cases, developers give this ability to the users. Now, it is up to the user to decide when and how many times to execute that function.
- The main difference between throttling and debouncing is that throttling executes the function at a regular interval, while debouncing executes the function only after some cooling period. Debouncing and throttling are not something provided by JavaScript itself.
- To put it in simple terms:
    - Throttling will delay executing a function. It will reduce the notifications of an event that fires multiple times.
    - Debouncing will bunch a series of sequential calls to a function into a single call to that function. It ensures that one notification is made for an event that fires multiple times.

**Debouncing**
![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/js/debouncing-code.png)

**Throttling**
![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/js/throttling-code.png)

http://demo.nimius.net/debounce_throttle/

#### 26.) Currying
Currying is a technique of evaluating function with multiple arguments, into sequence of functions with single argument.In other words, when a function, instead of taking all arguments at one time, takes the first one and return a new function that takes the second one and returns a new function which takes the third one, and so forth, until all arguments have been fulfilled.

Uses of currying function
- It helps to avoid passing same variable again and again.
- It is extremely useful in event handling. 

```
let multiply = function (x) {
    return function (y) {
        return x * y;
    }
}

let multiplyByTwo = multiply(2);
console.log(multiplyByTwo(3)); // 6

let add = function (x, y) {
    return x + y;
}

let addWithTwo = add.bind(this, 2);
console.log(addWithTwo(3)); // 5

let addWithTwo = add.bind(this, 2, 4);
console.log(addWithTwo(3)); // 6
```

#### 27.) Four Ways to Create Objects in JavaScript
- Object Literals.
    ```
    let car = {
        model: 'bmw',
        color: 'red',
        price: 2000
    }
    ```
- New operator or constructor.
    ```
    function Car(model, color) {
        this.model = model;
        this.color = color;
    }
    
    var c1 = new Car('BMW', 'red');
    ```
- Object.create method.
    ```
    var Car = {
        model: 'BMW',
        color: 'red'
    }
    
    var ElectricCar = Object.create(Car);
    console.log(ElectricCar.model); // BMW
    ```
- Class.
    ```
    class Car {
        constructor(maker, price) {
            this.maker = maker;
            this.price = price;
        }
    
        getInfo() {
            console.log(this.maker + " costs : " + this.price);
        }
    }
    ```

#### 28.) Event Bubbling, Capturing(Trickling)
- Event bubbling and capturing are two ways of event propagation in the HTML DOM API, when an event occurs in an element inside another element, and both elements have registered a handle for that event. The event propagation mode determines in which order the elements receive the event.
- With bubbling, the event is first captured and handled by the innermost element and then propagated to outer elements.
- With capturing, the event is first captured by the outermost element and propagated to the inner elements.
- Capturing is also called "trickling", which helps remember the propagation order:
`trickle down, bubble up`
- Back in the old days, Netscape advocated event capturing, while Microsoft promoted event bubbling. Both are part of the W3C Document Object Model Events standard (2000).
- IE < 9 uses only event bubbling, whereas IE9+ and all major browsers support both. On the other hand, the performance of event bubbling may be slightly lower for complex DOMs.
- We can use the addEventListener(type, listener, useCapture) to register event handlers for in either bubbling (default) or capturing mode. To use the capturing model pass the third argument as true.
- In event propagation, first capturing is happen and then bubbling when we use mix match(capturing for some and bubbling for some) to improve the performance
- `event.stopPropagation()` can used to stop propagation and all it will not bubble out and all event handler will not be called;

**Event bubbling**
```
document.querySelector("#child")
  .addEventListener('click', (e) => {
    console.log("Child Clicked!");
  });
  
document.querySelector("#child")
  .addEventListener('click', (e) => {
    console.log("Child Clicked!");
  }, false);
```

**Event trickling/capturing**
```
document.querySelector("#child")
  .addEventListener('click', (e) => {
    console.log("Child Clicked!");
  }, true);
```

![](https://github.com/iam-hitesh/interview_preparation/raw/main/images/js/eventflow.svg)

#### 29.) Event Delegation
DOM event delegation is a mechanism of responding to ui-events via a single common parent rather than each child, through the magic of event "bubbling" (aka event propagation).

#### 30.) forEach, map, find, filter & reduce
- forEach
- **map**: .map() when you want to transform elements of array to some other form/value and it will return array with mapped values
- **filter**: .filter() when you want to select a subset of multiple elements from an array.
- **find**: .find() When you want to select a single element from an array.
- **reduce**: .reduce() when you want derive a single value from multiple elements in an array.

**One of the biggest criticisms of .forEach() is the speed of the operation. So use forEach only when you can't use other**

#### 31.) Cross-Origin Resource Sharing (CORS)
Cross-Origin Resource Sharing (CORS) is an HTTP-header based mechanism that allows a server to indicate any other origins (domain, scheme, or port) than its own from which a browser should permit loading of resources. CORS also relies on a mechanism by which browsers make a “preflight” request to the server hosting the cross-origin resource, in order to check that the server will permit the actual request. In that preflight, the browser sends headers that indicate the HTTP method and headers that will be used in the actual request.

An example of a cross-origin request: the front-end JavaScript code served from https://domain-a.com uses XMLHttpRequest to make a request for https://domain-b.com/data.json.

For security reasons, browsers restrict cross-origin HTTP requests initiated from scripts. For example, XMLHttpRequest and the Fetch API follow the same-origin policy. This means that a web application using those APIs can only request resources from the same origin the application was loaded from unless the response from other origins includes the right CORS headers.

#### 32.) DOM & Virtual DOM
- **DOM(Document Object Model)**: It defines the logical structure of documents and the way a document is accessed and manipulated. DOM is a way to represent the webpage in a structured hierarchical way so that it will become easier for programmers and users to glide through the document. With DOM, we can easily access and manipulate tags, IDs, classes, Attributes, or Elements using commands or methods provided by the Document object.
- **Virtual DOM**: First of all - the Virtual DOM was not invented by React, but React uses it and provides it for free.
- **The Virtual DOM** is an abstraction of the HTML DOM. It is lightweight and detached from the browser-specific implementation details. Since the DOM itself was already an abstraction, the virtual DOM is, in fact, an abstraction of an abstraction.

#### 33.) PWA(Progressive Web Apps)
Progressive Web Apps are web apps that use emerging web browser APIs and features along with traditional progressive enhancement strategy to bring a native app-like user experience to cross-platform web applications. Progressive Web Apps are a useful design pattern, though they aren't a formalized standard. PWA can be thought of as similar to AJAX or other similar patterns that encompass a set of application attributes, including use of specific web technologies and techniques. This set of docs tells you all you need to know about them.

In order to call a Web App a PWA, technically speaking it should have the following features: Secure contexts (HTTPS), one or more Service Workers, and a manifest file.

#### 34.) Higher Order Components
A higher-order component (HOC) is an advanced technique in React for reusing component logic. HOCs are not part of the React API, per se. They are a pattern that emerges from React’s compositional nature.
Concretely, a higher-order component is a function that takes a component and returns a new 
component.

`const EnhancedComponent = higherOrderComponent(WrappedComponent);`

Whereas a component transforms props into UI, a higher-order component transforms a component into another component.
HOCs are common in third-party React libraries, such as Redux’s `connect` and Relay’s `createFragmentContainer.`

- Adding Functionality to Existing Components
- Ensuring Reusability of Code

#### 35.) React Hooks
- React Hooks are in-built functions that allow React developers to use state and lifecycle methods inside functional components, they also work together with existing code, so they can easily be adopted into a codebase. The way Hooks were pitched to the public was that they allow developers to use state in functional components but under the hood, Hooks are much more powerful than that. They allow React Developers to enjoy the following benefits:
    - Improved code reuse;
    - Better code composition;
    - Better defaults;
    - Sharing non-visual logic with the use of custom hooks;
    - Flexibility in moving up and down the **components** tree.
- With React Hooks, developers get the power to use functional components for almost everything they need to do from just rendering UI to also handling state and also logic — which is pretty neat.
- List of React Hooks
    - Basic Hooks
        - useState
        - **useEffect** (The function passed to useEffect will run after the render is committed to the screen. )
        - useContext
    - Additional Hooks
        - **useReducer** (An alternative to useState. Accepts a reducer of type (state, action) => newState, and returns the current state paired with a dispatch method. (If you’re familiar with Redux, you already know how this works.))
        - useCallback
        - **useMemo** (Returns a memoized value.)
        - useRef
        - useImperativeHandle
        - useLayoutEffect
        - useDebugValue

#### 36.) Memoization
Memoization is a form of caching where the return value of a function is cached based on its parameters. If the parameter of that function is not changed, the cached version of the function is returned. 

#### 37.) NPM, Yarn, Babel, and Webpack
- NPM and Yarn both are package manager, yarn is good in some aspects in comaprison to NPM, like yarn installed cached and fast packages.
- **Babel** - Babel is simply a translator/transpiler, who translates your 'fancy' (ES6+) JS code into 'not-so-fancy' (ES5) ones that browser (front-end) or Node.js (back-end) understands.
- **Webpack** - If Babel is a translator for JS, you can think of Webpack as a mega-multi-translator that works with all kinds of languages (or assets). For example, Webpack often runs Babel as one of its jobs. Another example, Webpack can collect all your inline CSS styles in your Javascript files and bundle them into one.
- Another important reason is that front-end doesn't work with modules (again, in most cases). Modules are built-in features of Node.js, not browsers. Nowadays developers are so used to npm install, import and export JS modules in front-end, as it allows us to better organize code and share packages. But in reality they are only syntactic sugars, and it's Webpack's job to figure out all the dependencies among all the modules that we use in the code, and compile them into one big chunk of JS code that the browser actually understands.
- webpack is a module bundler. Its main purpose is to bundle JavaScript files for usage in a browser, yet it is also capable of transforming, bundling, or packaging.

#### 38.) What is JSX
JSX stands for JavaScript XML.
It allows us to write HTML inside JavaScript and place them in the DOM without using functions like appendChild( ) or createElement( ).
As stated in the official docs of React, JSX provides syntactic sugar for React.createElement( ) function.
**Note- We can create react applications without using JSX as well.**


## Coding Questions
- [ ] Search Bar Implementation (use concept of Debouncing)
- [ ] [Identical DOM Node](https://codepen.io/hiteish/pen/YzpJGXK)
