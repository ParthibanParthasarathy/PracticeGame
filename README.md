# C++ OOP Topics Review

## Header Files and Source Files
- **Header Files (`.h`)**: Contain declarations such as class definitions, function prototypes, and constants. They are included in source files using `#include`.
- **Source Files (`.cpp`)**: Contain the implementation of the functions and classes declared in header files.

## Header Guards
- Prevent multiple inclusions of the same header file, which can cause redefinition errors.
- Example:
  ```cpp
  #ifndef HEADER_NAME
  #define HEADER_NAME
  // Declarations
  #endif
  ```

## Class Definition
- A class is a blueprint for creating objects. It defines attributes (data members) and methods (member functions).
- Example:
  ```cpp
  class MyClass {
  public:
      int attribute;
      void method();
  };
  ```

## Instance, Static, and Dynamic Objects
- **Instance**: Regular objects created on the stack. These objects are automatically destroyed when they go out of scope, and their memory is managed by the compiler. Instance objects are the most common type of object and are used when the lifetime of the object is tied to the scope in which it is declared.
  ```cpp
  MyClass obj; // Instance object
  obj.method(); // Accessing methods or attributes
  ```
  - **Advantages**:
    - Simple to use and manage.
    - No need to manually allocate or deallocate memory.
  - **Disadvantages**:
    - Limited to the scope in which they are declared.

- **Static**: Objects that are shared among all instances of a class. Static objects are created only once and persist throughout the program's lifetime. They are useful for maintaining state or shared data across multiple objects or function calls.
  ```cpp
  static MyClass obj; // Static object
  obj.method(); // Accessing methods or attributes
  ```
  - **Advantages**:
    - Shared across all instances, reducing memory usage for shared data.
    - Lifetime spans the entire program, making them ideal for global state.
  - **Disadvantages**:
    - Can lead to unexpected behavior if not managed carefully (e.g., global state issues).

- **Dynamic**: Objects created on the heap using the `new` keyword. These objects are manually managed, meaning you must explicitly delete them to free memory. Dynamic objects are useful when the size or lifetime of the object is not known at compile time.
  ```cpp
  MyClass* obj = new MyClass(); // Dynamic object
  obj->method(); // Accessing methods or attributes
  delete obj; // Free memory
  ```
  - **Advantages**:
    - Flexible lifetime, as they persist until explicitly deleted.
    - Useful for creating objects whose size or number is determined at runtime.
  - **Disadvantages**:
    - Requires manual memory management, which can lead to memory leaks or dangling pointers if not handled properly.

- **Comparison Table**:
  | Type     | Memory Location | Lifetime                  | Management         |
  |----------|-----------------|---------------------------|--------------------|
  | Instance | Stack           | Scope-bound               | Automatic          |
  | Static   | Data Segment    | Entire program lifetime   | Automatic          |
  | Dynamic  | Heap            | Until explicitly deleted  | Manual             |

## Allocating Array of Objects
- **Definition**: An array of objects is a collection of objects of the same class, stored in contiguous memory locations. Arrays of objects allow you to manage multiple instances of a class efficiently.

- **Stack Allocation**:
  - Arrays of objects can be created on the stack, and their memory is automatically managed by the compiler.
  - Example:
    ```cpp
    class MyClass {
    public:
        int value;
        MyClass(int v) : value(v) {}
    };

    int main() {
        MyClass arr[3] = { MyClass(1), MyClass(2), MyClass(3) };
        for (int i = 0; i < 3; i++) {
            std::cout << arr[i].value << std::endl;
        }
        return 0;
    }
    ```

- **Heap Allocation**:
  - Arrays of objects can also be created on the heap using the `new` keyword. This requires manual memory management.
  - Example:
    ```cpp
    class MyClass {
    public:
        int value;
        MyClass(int v) : value(v) {}
    };

    int main() {
        MyClass* arr = new MyClass[3]{ MyClass(1), MyClass(2), MyClass(3) };
        for (int i = 0; i < 3; i++) {
            std::cout << arr[i].value << std::endl;
        }
        delete[] arr; // Free memory
        return 0;
    }
    ```

- **Default Constructor Requirement**:
  - When creating an array of objects, the class must have a default constructor if no arguments are provided during initialization.
  - Example:
    ```cpp
    class MyClass {
    public:
        int value;
        MyClass() : value(0) {} // Default constructor
    };

    int main() {
        MyClass arr[3]; // Uses default constructor
        return 0;
    }
    ```

- **Accessing Elements**:
  - Use the subscript operator (`[]`) to access individual objects in the array.
  - Example:
    ```cpp
    arr[0].value = 10;
    std::cout << arr[0].value << std::endl;
    ```

- **Advantages**:
  - Efficient way to manage multiple objects of the same type.
  - Simplifies iteration and bulk operations.

- **Disadvantages**:
  - Fixed size for stack-allocated arrays.
  - Requires manual memory management for heap-allocated arrays.

## Explanation of `MyClass(int v) : value(v) {}`
- **Definition**: This syntax is known as a **member initializer list** in C++. It is used to initialize class members directly before the constructor body is executed.

- **Purpose**:
  - Provides a concise way to initialize data members.
  - Ensures that members are initialized as the object is created, rather than being assigned values later in the constructor body.
  - Particularly useful for initializing `const` members, reference members, or members of types that do not have a default constructor.

- **Example in Context**:
  ```cpp
  class MyClass {
  public:
      int value;

      // Constructor using member initializer list
      MyClass(int v) : value(v) {}
  };

  int main() {
      MyClass obj(10); // Initializes 'value' to 10
      return 0;
  }
  ```

- **How It Works**:
  - `MyClass(int v) : value(v) {}` initializes the `value` member with the value of `v` before the constructor body is executed.
  - Equivalent to:
    ```cpp
    MyClass(int v) {
        value = v; // Assignment happens after the object is created
    }
    ```
    However, the member initializer list is more efficient because it avoids default initialization followed by assignment.

- **Advantages**:
  1. **Efficiency**: Direct initialization avoids unnecessary default construction and reassignment.
  2. **Required for Certain Members**: Members like `const` variables, references, or objects without a default constructor must be initialized using a member initializer list.

- **Example with `const` Member**:
  ```cpp
  class MyClass {
  public:
      const int value;

      MyClass(int v) : value(v) {} // Must use member initializer list for 'const' member
  };
  ```

- **Best Practices**:
  - Use member initializer lists whenever possible for initialization.
  - Keep the initializer list simple and avoid complex logic.

## Access Specifiers
- **Private**: Accessible only within the class.
- **Protected**: Accessible within the class and derived classes.
- **Public**: Accessible from anywhere.

## Member-Wise Assignment
- **Definition**: Member-wise assignment is the default behavior of the assignment operator (`=`) in C++. When one object is assigned to another, each data member of the source object is copied to the corresponding data member of the target object.

- **How It Works**:
  - For primitive data types (e.g., `int`, `float`), the values are directly copied.
  - For pointers, only the pointer value (address) is copied, not the data it points to. This can lead to shallow copies.

- **Example**:
  ```cpp
  class MyClass {
  public:
      int a;
      float b;
  };

  int main() {
      MyClass obj1;
      obj1.a = 10;
      obj1.b = 20.5;

      MyClass obj2;
      obj2 = obj1; // Member-wise assignment

      // obj2.a is now 10, obj2.b is now 20.5
      return 0;
  }
  ```

- **Shallow Copy Issue**:
  If a class contains pointers, member-wise assignment can lead to shallow copies, where multiple objects share the same memory. This can cause issues when one object modifies or deletes the shared memory.

  ```cpp
  class MyClass {
  public:
      int* ptr;

      MyClass(int value) {
          ptr = new int(value);
      }

      ~MyClass() {
          delete ptr;
      }
  };

  int main() {
      MyClass obj1(10);
      MyClass obj2;
      obj2 = obj1; // Shallow copy: obj2.ptr points to the same memory as obj1.ptr

      // Deleting obj1 will cause obj2.ptr to become a dangling pointer
      return 0;
  }
  ```

- **Solution**: To avoid shallow copies, implement a custom assignment operator (deep copy).

  ```cpp
  class MyClass {
  public:
      int* ptr;

      MyClass(int value) {
          ptr = new int(value);
      }

      ~MyClass() {
          delete ptr;
      }

      // Custom assignment operator
      MyClass& operator=(const MyClass& obj) {
          if (this != &obj) { // Avoid self-assignment
              delete ptr; // Free existing memory
              ptr = new int(*obj.ptr); // Deep copy
          }
          return *this;
      }
  };

  int main() {
      MyClass obj1(10);
      MyClass obj2;
      obj2 = obj1; // Deep copy: obj2.ptr points to a new memory location

      return 0;
  }
  ```

## Constructors
- **Default Constructor**: No parameters.
  ```cpp
  MyClass() {}
  ```
- **Parameterized Constructor**: Accepts arguments.
  ```cpp
  MyClass(int x) { attribute = x; }
  ```
- **Overloaded Constructor**: Multiple constructors with different parameters.
- **Copy Constructor**: Creates a new object as a copy of an existing object.
  ```cpp
  MyClass(const MyClass& obj) { attribute = obj.attribute; }
  ```

## Copy Constructor
- **Definition**: A copy constructor is a special constructor in C++ used to create a new object as a copy of an existing object. It initializes the new object with the values of the existing object's data members.

- **Default Copy Constructor**:
  - If no copy constructor is explicitly defined, the compiler provides a default copy constructor.
  - The default copy constructor performs a shallow copy, which can lead to issues if the class contains pointers.

- **Syntax**:
  ```cpp
  ClassName(const ClassName& obj);
  ```

- **Example**:
  ```cpp
  class MyClass {
  public:
      int a;
      int* b;

      // Constructor
      MyClass(int x, int y) {
          a = x;
          b = new int(y);
      }

      // Copy Constructor
      MyClass(const MyClass& obj) {
          a = obj.a;
          b = new int(*obj.b); // Deep copy
      }

      ~MyClass() {
          delete b;
      }
  };

  int main() {
      MyClass obj1(10, 20);
      MyClass obj2 = obj1; // Copy constructor is called

      // obj2.a is 10, obj2.b points to a new memory location with value 20
      return 0;
  }
  ```

- **Shallow Copy vs Deep Copy**:
  - **Shallow Copy**: Copies the pointer value (address) but not the data it points to. This can lead to dangling pointers or double deletion issues.
  - **Deep Copy**: Allocates new memory and copies the actual data, ensuring that the new object has its own copy of the data.

- **When to Use a Custom Copy Constructor**:
  - When the class contains pointers or dynamically allocated resources.
  - To ensure proper resource management and avoid shallow copy issues.

- **Best Practices**:
  - Always implement a copy constructor if your class manages dynamic memory.
  - Use `const` in the parameter to prevent accidental modification of the source object.
  - Combine the copy constructor with a custom assignment operator and destructor to follow the Rule of Three.

## Setter Methods (Mutators)
- Modify private attributes.
  ```cpp
  void setAttribute(int value) { attribute = value; }
  ```

## Getter Methods (Accessors)
- Access private attributes.
  ```cpp
  int getAttribute() const { return attribute; }
  ```

## `this` Keyword
- Refers to the current object.
  ```cpp
  void setAttribute(int value) { this->attribute = value; }
  ```

## Static Attributes and Methods
- **Static Attributes**: Shared across all instances of the class.
  ```cpp
  static int count;
  ```
- **Static Methods**: Can be called without an instance.
  ```cpp
  static void displayCount();
  ```

## Static Variables as Private Members
- **Definition**: Static variables can be declared as private within a class. This ensures that the variable is shared among all instances of the class but is not directly accessible outside the class.

- **Purpose**: Encapsulation ensures that the static variable can only be accessed or modified through controlled methods, maintaining data integrity.

- **Example**:
  ```cpp
  #include <iostream>
  using namespace std;

  class MyClass {
  private:
      static int count; // Private static variable

  public:
      // Getter for the static variable
      static int getCount() {
          return count;
      }

      // Setter for the static variable
      static void setCount(int value) {
          count = value;
      }
  };

  // Definition and initialization of the static variable
  int MyClass::count = 0;

  int main() {
      // Accessing the private static variable through public methods
      cout << "Initial Count: " << MyClass::getCount() << endl;

      MyClass::setCount(5);
      cout << "Updated Count: " << MyClass::getCount() << endl;

      return 0;
  }
  ```

- **Key Points**:
  1. **Initialization**: Static variables must be defined and initialized outside the class definition.
  2. **Access**: Since the variable is private, it can only be accessed or modified through public static methods.
  3. **Encapsulation**: This approach ensures that the static variable is not directly exposed, allowing for better control over its usage.

## Using the Class Inside the Class Declaration
- **Definition**: In C++, a class can use its own type within its declaration. This is typically done using pointers or references, as the size of the class is not fully known until its definition is complete.

- **Common Use Cases**:
  1. **Self-Referencing Pointers**:
     - A class can have a pointer to an object of its own type. This is often used in data structures like linked lists or trees.
     - Example:
       ```cpp
       class Node {
       public:
           int data;
           Node* next; // Pointer to the next Node

           Node(int value) : data(value), next(nullptr) {}
       };
       ```

  2. **Friendship**:
     - A class can declare another instance of itself as a friend to allow access to private or protected members.
     - Example:
       ```cpp
       class MyClass {
       private:
           int value;

       public:
           MyClass(int v) : value(v) {}

           friend bool compare(const MyClass& a, const MyClass& b);
       };

       bool compare(const MyClass& a, const MyClass& b) {
           return a.value == b.value;
       }
       ```

  3. **Static Members**:
     - A class can have static members of its own type, as static members are shared across all instances and do not depend on the size of the class.
     - Example:
       ```cpp
       class MyClass {
       public:
           static MyClass* instance;
       };

       MyClass* MyClass::instance = nullptr;
       ```

- **Key Points**:
  - Directly declaring an object of the same class type inside the class is not allowed because it would create an infinite recursion in memory allocation.
  - Using pointers or references avoids this issue, as they do not require the full size of the class to be known at the time of declaration.

- **Advantages**:
  - Enables the creation of complex data structures like linked lists, trees, and graphs.
  - Facilitates design patterns like singletons and factories.

- **Disadvantages**:
  - Requires careful memory management to avoid issues like memory leaks or dangling pointers.

## Friend Functions and Classes
- **Friend Function**: Can access private/protected members of a class.
  ```cpp
  friend void display(MyClass obj);
  ```
- **Friend Class**: Another class can access private/protected members.
  ```cpp
  friend class AnotherClass;
  ```

## Destructor
- Cleans up resources when an object is destroyed.
  ```cpp
  ~MyClass() {}
  ```

## Inline Functions
- **Definition**: Inline functions are functions whose code is expanded at the point of invocation, rather than being called through the usual function call mechanism. This can reduce the overhead of function calls for small, frequently used functions.

- **How to Define**:
  - Functions defined inside a class are implicitly inline, even if the `inline` keyword is not explicitly used. This is because the compiler treats them as inline by default.
  - Example:
    ```cpp
    class MyClass {
    public:
        void greet() { // Implicitly inline
            std::cout << "Hello, World!" << std::endl;
        }
    };
    ```

  - You can also explicitly use the `inline` keyword for functions defined outside the class.
    ```cpp
    class MyClass {
    public:
        inline void greet();
    };

    inline void MyClass::greet() {
        std::cout << "Hello, World!" << std::endl;
    }
    ```

- **Advantages**:
  - Eliminates the overhead of function calls (e.g., stack operations).
  - Can improve performance for small, frequently called functions.

- **Disadvantages**:
  - Increases the size of the binary if the function is large and used frequently (code bloat).
  - The compiler may ignore the `inline` behavior if the function is too complex.

- **When to Use**:
  - For small, simple functions that are called frequently.
  - Avoid using inline for large or complex functions to prevent code bloat.

## Private Member Functions
- Helper functions accessible only within the class.

## Overloaded Functions
- Functions with the same name but different parameters.
  ```cpp
  void display(int x);
  void display(double y);
  ```

## Operator Overloading
- **Arithmetic Operators**: `+`, `-`, etc.
  ```cpp
  MyClass operator+(const MyClass& obj);
  ```
- **Assignment Operator**: `=`.
  ```cpp
  MyClass& operator=(const MyClass& obj);
  ```
- **Stream Insertion/Extraction**: `<<`, `>>`.
  ```cpp
  friend ostream& operator<<(ostream& out, const MyClass& obj);
  ```

## L-Values and R-Values
- **L-Value**: Has a memory address.
- **R-Value**: Temporary value.

## Inheritance
- **Definition**: Inheritance is a mechanism in C++ that allows a class (called the derived class) to inherit attributes and methods from another class (called the base class). It promotes code reuse and establishes a relationship between classes.

- **Types of Inheritance**:
  1. **Single Inheritance**: A derived class inherits from one base class.
     ```cpp
     class Base {
     public:
         void display() {
             std::cout << "Base class method" << std::endl;
         }
     };

     class Derived : public Base {
     public:
         void show() {
             std::cout << "Derived class method" << std::endl;
         }
     };

     int main() {
         Derived obj;
         obj.display(); // Accessing base class method
         obj.show();    // Accessing derived class method
         return 0;
     }
     ```

  2. **Multiple Inheritance**: A derived class inherits from more than one base class.
     ```cpp
     class Base1 {
     public:
         void display1() {
             std::cout << "Base1 class method" << std::endl;
         }
     };

     class Base2 {
     public:
         void display2() {
             std::cout << "Base2 class method" << std::endl;
         }
     };

     class Derived : public Base1, public Base2 {
     public:
         void show() {
             std::cout << "Derived class method" << std::endl;
         }
     };

     int main() {
         Derived obj;
         obj.display1(); // Accessing Base1 method
         obj.display2(); // Accessing Base2 method
         obj.show();     // Accessing derived class method
         return 0;
     }
     ```

  3. **Multilevel Inheritance**: A class inherits from a derived class, forming a chain.
     ```cpp
     class Base {
     public:
         void display() {
             std::cout << "Base class method" << std::endl;
         }
     };

     class Intermediate : public Base {
     public:
         void show() {
             std::cout << "Intermediate class method" << std::endl;
         }
     };

     class Derived : public Intermediate {
     public:
         void print() {
             std::cout << "Derived class method" << std::endl;
         }
     };

     int main() {
         Derived obj;
         obj.display(); // Accessing Base class method
         obj.show();    // Accessing Intermediate class method
         obj.print();   // Accessing Derived class method
         return 0;
     }
     ```

  4. **Hierarchical Inheritance**: Multiple derived classes inherit from a single base class.
     ```cpp
     class Base {
     public:
         void display() {
             std::cout << "Base class method" << std::endl;
         }
     };

     class Derived1 : public Base {
     public:
         void show() {
             std::cout << "Derived1 class method" << std::endl;
         }
     };

     class Derived2 : public Base {
     public:
         void print() {
             std::cout << "Derived2 class method" << std::endl;
         }
     };

     int main() {
         Derived1 obj1;
         Derived2 obj2;
         obj1.display(); // Accessing Base class method
         obj1.show();    // Accessing Derived1 class method
         obj2.display(); // Accessing Base class method
         obj2.print();   // Accessing Derived2 class method
         return 0;
     }
     ```

  5. **Hybrid Inheritance**: A combination of two or more types of inheritance.

- **Access Specifiers in Inheritance**:
  - **Public Inheritance**: Public and protected members of the base class remain public and protected in the derived class.
  - **Protected Inheritance**: Public and protected members of the base class become protected in the derived class.
  - **Private Inheritance**: Public and protected members of the base class become private in the derived class.

- **Constructor in Inheritance**:
  - The base class constructor is called first, followed by the derived class constructor.
  - Example:
    ```cpp
    class Base {
    public:
        Base() {
            std::cout << "Base class constructor" << std::endl;
        }
    };

    class Derived : public Base {
    public:
        Derived() {
            std::cout << "Derived class constructor" << std::endl;
        }
    };

    int main() {
        Derived obj; // Calls Base constructor first, then Derived constructor
        return 0;
    }
    ```

- **Advantages**:
  - Promotes code reuse.
  - Establishes a clear relationship between classes.

- **Disadvantages**:
  - Can lead to complexity in multiple inheritance (e.g., diamond problem).
  - Requires careful design to avoid unintended behavior.

## Redefining vs Overriding
- **Redefining**: Hides base class method.
- **Overriding**: Replaces base class method (with `virtual`).

## Binding
- **Static Binding**: Compile-time (non-virtual methods).
- **Dynamic Binding**: Runtime (virtual methods).

## Virtual Functions/Polymorphism
- Enable dynamic method dispatch.
  ```cpp
  virtual void method();
  ```

## Pure Virtual Functions and Abstract Classes
- **Pure Virtual Function**: Declared with `= 0`.
  ```cpp
  virtual void method() = 0;
  ```
- **Abstract Class**: Contains at least one pure virtual function.

## Recursion
- A function calls itself.
  ```cpp
  int factorial(int n) {
      if (n == 0) return 1;
      return n * factorial(n - 1);
  }
  ```

## Iterative vs Recursive Methods
- **Iterative**: Uses loops.
- **Recursive**: Uses function calls.
- Conversion involves replacing recursion with loops or vice versa.

---
This review covers all the requested topics in-depth and is beginner-friendly. Let me know if you need further clarification!