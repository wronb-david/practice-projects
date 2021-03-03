## Topics to look into:

### Theoretical Topics

* Design Pattern refresher (Builder, Visitor, Observer ...)

### Practical Topics

#### C# related

* "sealed" classes
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


## Theory topics I recently looked into:

### Design Principles: SOLID
* Single Responsibility Principle

Classes should have one well defined responsibility. Something within their responsibility chainging, should be the only reason for change of a given entity.

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