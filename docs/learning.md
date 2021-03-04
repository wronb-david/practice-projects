## Topics to look into:

### Theoretical Topics

* Design Pattern refresher (Builder, Visitor, Observer ...)

### Practical Topics

#### C# related

* "sealed" classes
* Generics and how to constrain them
* static code analyzers for C#/.net (like ClangTidy, CppCheck in C++ and PMD in Java)
* Dependency Injection
* Unit Testing: Mocking
* Connecting to SQL-Databases (esp. local Sqlite files and remote MySQL servers)
  - Storing binary data in SQL-Databases
* Talking to RESTful APIs
* Deeper look into Async & Tasks

#### C++ related

* C++20 Concepts
* C++20's compile time programming expansion
  - constexpr algorithms, consteval


## Topics I recently looked into:

### Design Principles: SOLID
* Single Responsibility Principle

Aims to ensure that classes have exactly one well defined responsibility. The only reason for change of a given entity, should be that something within ther responsibility changes.

* Open Close Principle

Aims to ensure that entities remain open for extension, but closed for modification, once deployed. This promotes the use of interfaces or abstract base classes as dependencies. New implementations can provide the necessary extensions, without having to modify the existing classes.

* Liskov Substitution Principle 

Aims to ensure well crafted class hierarchies, such that substituting a class A with its subclass B:A will not break existing code. B:A may provide additional features over A, but may not change how it handles the public inteface of A - e.g. by not implementing a method.

To achieve this base classes have to be well crafted by ensuring that they're the smalles common denominator within their hierarchy - as the age old design saying proclaims:

> A designer knows he has achieved perfection not when there is nothing left to add, but when there is nothing left to take away.


* Interface Segregation Principle

Aims to ensure that basic interfaces are kept as narrow as possible. These basic interfaces can then be composed (e.g. IBorrowableBook : IBook, IBorrowable).

* Dependency Inversion Principle

Aims to ensure that dependencies between entities in a program are communicated via abstractions (interfaces) rather than implementations. This way any potential external dependencies (database, logger) can be replaced in testing.

---

Following these principles creates code for which it is much easier to create unit tests as former hard dependencies have been replaced with interfaces. For these interfaces "mock-up" replacements can be provided. Defining the scope of each entity more narrowly (Single Responsibility) helps a lot. 

On the other hand it is not always immediately obvious how far these principles should be taken: 
- When is it fine to depend on an impementaion rather than an interface?
- What constitutes as a single responsibility? How granular should this be?

### C# access modifiers

* Public

Accessible everywhere.

* Private

Only accessible within the same class.

* Protected

Accessible downwards in the class hierarchy.

* Internal

Only accessible within the same assembly (e.g. the same class library / dll)

* Protected Internal

Makes internal fields available to the assemblies of any sub-classes.

* Private Protected

Limits protected to the same assembly. Only subclasses within the same assembly can access fields with this modifier, while subclasses in other assemblies cannot.

### Verbatim String Literals

```c#
string nonverbatim = "C:\\temp\\target.txt";
string    verbatim = @"C:\temp\target.txt";
```

Unlike normal string literals verbatim string literals do not convert escape sequences (\t, \u0041, \x0041), but rather take these literally, which makes them a great option for windows path strings as there's no need to escape the backslashes.