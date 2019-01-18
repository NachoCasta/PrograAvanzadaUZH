# PrograAvanzadaUZH

## Preguntas Examen
- [x] 1. **Wie koennen Mitglieder einer Klasse („class members“) im Konstruktor initialisiert warden, unabhaengig davon ob diese Mitglieder ueber einen „default constructor“ verfuegen oder nicht?**
   (How can members of a class (class members) be initialized in the constructor, regardless of whether these members have a default constructor or not?)

   In the `:` section. This will initialize the members skipping the default constructor. Example:\
   `Fraction(int numerator, int denominator): n(numerator), d(denominator) { ... }`

- [x] 2. **Wie kann man verhindern, daß die vom Compiler generierten Klassenartefakte versehentlich verwendet werden (mit und ohne Verwendung von C++11 Funktionalitaet)?**
   (How can you prevent the compiler-generated class artifacts from being inadvertently used (with and without the use of C ++ 11 functionality)?)

   By calling functions with a reference or pointer, to avoid the function from copying the object in every call.

- [x] 3. **Was bedeutet es wenn eine Funktion einer Klasse („member function“) als const deklarert worden ist?  Wann sollte man eine Funktion einer Klasse als const deklarieren?**
   (What does it mean when a function of a class ("member function") has been declared const? When should one declare a function of a class as const?)

   It means that the function will not change the object on which they are called. One should declare a function of a class const when the function does not modify the instance of the class or to avoid accidental modifications. This will also let us use the function when we call the function from a const instance of the class.

- [x] 4. **In C++ kann sich const auf unterschiedliche Teile eines Typs beziehen.  Nennen Sie zumindest zwei unterschiedliche Beispiele und erklaeren sie anhand dieser die entsprechende Implikation.**
   (In C ++, const can refer to different parts of a type. Give at least two different examples and explain the corresponding implication.)

   1. `const vector<string> v1`
      Indicates that the object `v1` is constant
   2. `const vector<string> *vp = v1`
      Indicates that the object that the pointer `vp` is pointing to is constant
   3. `const vector<string> *const vp = v1`
      Indicates that the pointer `vp` is constant, i.e. you can not change where `vp` is pointing to.

- [x] 5. **Erklaeren Sie die Bedeutung des Schluesselwortes constexpr und in welcher Situation dieses sinnvollerweise eingesetzt werden kann.**
   (Explain the meaning of the keyword constexpr and in which situation it can be usefully used.)

   This keyword allows you to use functions in constant expressions (which normally you cant). This way, the value will be computed in compile time. One of the uses cases could be in static_assert, where you need to compute everything in compile time.

- [x] 6. **Erklaeren Sie die Bedeutung des Schluesselwortes inline und wie dieses sinnvollerweise eingesetzt werden kann, insbesondere im Zusammenhang von Projekten, die aus mehreren Objektdateien bestehen (und auch insbesondere wenn „link-time optimization“ nicht zur Verfuegung steht).**
   (Explain the meaning of the keyword inline and how it can be reasonably used, especially in the context of projects that consist of several object files (and especially if "link-time optimization" is not available).)

   The inline keyword is used before a function declaration to create an "inline function". The compiler will replace every call to this function with the function body, so that your program doesn't have to call the function all the time. It's very useful if you have a simple function that you use in many places but you don't want to copy and paste the same code all over your code. If the inline function is going to be used globally (in different object files), the function has to be defined in the header file.

- [x] 7. **Unter welchen Umstaenden gehoeren templates und als inline deklarierte Funktionen in die Headerdatei (*.h) und unter welchen in die Implementierungsdatei (*.cc)? Erklaeren Sie weshalb.**
   (Under what circumstances do templates and inline declared functions belong in the header file (* .h) and under which in the implementation file (* .cc)? Explain why.)

  Under every circumstance templates and inline declared functions have to go in the header file, because the code needs to be known in compile time.

- [x] 8. **Erklaeren Sie die Bedeutung des Schluesselwortes friend und wo dieses sinnvollerweise eingesetzt werden kann.**
   (Explain the meaning of the keyword friend and where this can be meaningfully used.)

   It lets you declare another class or function as a friend, which lets them access private and protected members of the class where the friend declaration appears. One of the use cases would be when defining the std::istream and std::ostream operators. Another use case would be classes that have a close relationship to each other, for example: matrix and vector.

- [x] 9. **Erklaeren Sie den Unterschied zwischen Pointer und Reference. Worauf ist insbesondere bei Objekten, die auf dem Stack liegen aufzupassen?**
   (Explain the difference between Pointer and Reference. What is especially important for watching objects that are on the stack?)

   References cannot be changed to point to a different value.  It refers to the value, not to the location in memory where it's stored. They can change the value just like pointers but in an "invisible" way.

- [x] 10. **Was ist der unterschied zwischen einer virtuellen und nicht virtuellen "member function" (Methode)?  Wozu dient die virtuelle Methodentabelle?**
   (What is the difference between a virtual and a non-virtual "member function" (method)? What is the virtual method table for?)

   A virtual member function defines an interface to be used. They are meant to be overriden by the childrens that inherit the class which this functions belong to. The virtual method table is a table that is created for the virtual member function to decide the apropiate function to be called when the function is called, because you may not be able to tell this in compile time so it has to be done dynamically.

- [x] 11. **C++ erlaubt es die Operatoren +, -, ``*``, /, etc zu ueberladen.  Worauf sollte man dabei (im Allgemeinen) im Sinne der Lesbarkeit des Programmes aufpassen?**
   (C ++ allows the operators +, -, ``*``, /, etc to be overloaded. What should be taken care of (in general) in terms of the readability of the program?)

   We should always adhere to mathematical properties and laws so that our operators make sense. For example we should to take associativity, commutativity, reflexivity, symmetry and transitivity into consideration and make sure that it is fulfilled.

- [x] 12. **Was besagt die „rule of three“? Wieso ist sie so wichtig?**
   (What does the "rule of three" mean? Why is she so important?)

   It says that if you implement either of the following three, you most likely need all three of them:
   - Copy Constructor
   - Assignment Operator
   - Destructor
   It's important to make sure that we are managing the memory in the right way and that we are not leaving unfreed memory somewhere in the way.

- [x] 13. **Wie werden in C++ ueblicherweise benutzerdefinierte Ein- und Ausgaberoutinen implementiert?  Was ist im Fehlerfall zu beachten?**
   (How is custom input and output routines implemented in C ++? What should be considered in case of error?)

   You have to implement the std::istream and std::ostream operator and make sure that they also return an std::istream or a std::ostream, respectively.

- [x] 14. **Wie koennen Sie in C++ einen benutzerdefinierten Konversionsoperator implementieren?**
   (How can you implement a custom conversion operator in C ++?)

   We define a member function in the class with the `operator` keyword. For example, to convert a fraction to a double we would do it like this:\
   `operator double() { return (double) c/d }`

- [x] 15. **Welche Arten von Polymorphismus gibt es?**
   (What types of polymorphism exist?)

   - Ad hoc, with overloading. Resolved during compile time
   - Dynamic using virtual member functions. Resolved during run time (using virtual method table)
   - Static/Parametric using templates. Resolved during compile time. Concrete functions/classes are generated for each parameter type

- [x] 16. **Was passiert in C++ (intern) wenn ein Template mit unterschiedlichen Templateparametern verwendet wird?  Was ist ein Vorteil dieser Implementierung?**
   (What happens in C ++ (internally) when a template with different template parameters is used? What is an advantage of this implementation?)

   Concrete functions and classes are generated by the compiler everytime the template is used with parameters that have not been used before. An advantage of this is that you can program generic functions that work the same independent of the the data type and the compiler will do the work of repeating them for every type you want to use them for.

- [x] 17. **Erklaeren Sie die Funktion von C++ Iteratoren?  Wie werden diese verwendet?  Was sind deren Eigenschaften?**
   (Explain the function of C ++ iterators? How are these used? What are their properties?)

   They define a sequence over the elements of a container and are usually used to iterate over these elements.\
   A standard way of using them would be:
   ```
   C container;
   auto fst = container.begin(),
        cur = fst,
        lst = container.end();
   while (cur != lst) {
      do_something(cur)
      ++cur;
   }
   ```
   Properties of iterators:
   - They point to the element
   - Allow flexibility cause iterator does not know about begin or end
   - If bounds are exceeded, you get an undefined behaviour (probably segmentation fault)

- [x] 18. **Was ist eine trait Klasse.**
   (What is a trait class.)

   It's a class used to factor out certain behaviours (possible in a template) in order to be able to specialize for different types. You could then pass the trait class to the template so that it knows how to behave with that data type.

- [x] 19. **Vergleichen Sie eine trait Klasse mit einer puren virtuellen Klasse („interface“).**
   (Compare a trait class with a pure virtual class ("interface").)

   Both trait and virtual classes are meant to define an interface to be used with the difference that virtual classes specify this interface in the class itself to be specialized through inheritance and traits lets you out source certain behaviours in a different class, so that you can specialize those behaviours in that class and then pass your trait to your class template as an argument.

- [x] 20. **Weshalb werden in C++ (wie auch in C) Headerdateien (``*``.h) benoetigt? Welche Artifakte gehoeren daher prinzipiell in die Headerdatei?**
   (Why are header files (``*`` .h) required in C ++ (as well as in C)? Which artifacts are therefore part of the header file?)

   They are required for separate compilation and store the object file's interfaces. Everything that's going to be exported (to be use outside of that file) should go in the header file, so that other files can know those interfaces. This includes: variable declarations, function declarations, type declarations, etc. Code that needs to be known in compile time also needs to go in the header. This includes: inline functions (if used globally) and templates.

- [x] 21. **Wozu wird der move constructor verwendet?**
   (What is the move constructor used for?)

   It's invoked by the compiler when it knows that the object will be destroyed after copying the object. It's used mostly to return values. That way, you can avoid copying the value twice.

- [x] 22. **Erklaeren Sie das „copy and swap“ Idiom. Was sind dessen Vorteile?**
   (Explain the "copy and swap" idiom. What are its advantages?)

   It solves the problem of the right way of specifying the The Big Three. You need a well defined Copy constructor which is usually easy to define, a Destructor which is also easy and a Swap function. Then, to define the assignment operator, you create a temporary copy of your object and then swap it with the new data and finally destructing the copy which takes the old data with it.

- [x] 23. **Was ist ein function object?  Wie kann dieses sinnvoll verwendet werden? Was ist eine lambda function? Wie unterscheidet sich diese von einem function object?**
   (What is a function object? How can this be used meaningfully? What is a lambda function? How does this differ from a function object?)

   It's an instance of a class that implements operator(). With this, you can for example store common information to be used for every different call of the function, like a max_value so far or something like that. A lambda function is an anonymous function object. It's very similar to a functin object, with the advantage that you can define it right were you are going to call it, so you could say it's more elegant. It also let's you keep state between calls to the function, just like a function object.

- [x] 24. **C++ erlaubt es statisch anhand von Typdefinitionen eines template parameters unterschiedliche Implementierungen einer Funktion auszuwaehlen (tag dispatching).  Erklaeren Sie den Mechanismus anhand eines Beispiels.**
   (C ++ allows the static selection of different implementations of a function based on type definitions of a template parameter (tag dispatching). Explain the mechanism with an example.)

   You can specialize templates for specific data types, with different implementations that suit that specific data type. The compiler will priorize the specified templates, so in case that a use also fits the general template, it will still choose a specified one if there is one available.

- [x] 25. **C++ erlaubt es statisch mittels SFINAE (Substitution Failure Is Not An Error) anahnd von Eigenschaften eines templates unterschiedliche Implementierungen einer Funktion auszuwaehlen).  Erklaeren Sie die Funktionsweise.**
   (C ++ allows you to statically select different implementations of a function using SFINAE (Substitution Failure Is Not An Error). Explain how it works.)

   When we invoke a function the compiler collects all functions that may be used and selects the most appropiate one for its arguments. If the function is generic and any of the parameters doesnt match, the compiler would normally stop, but would SFINAE it would continue, which would sometimes be a desirable behaviour.

- [x] 26. **Erklaeren Sie den unterschied zwischen „class Sub : [public, protected, private] Base“?  Was sind die Implikationen, insbesondere auch auf die Vererbung des Types der Basisklasse.**
   (Explain the difference between "class Sub: [public, protected, private] Base"? What are the implications, especially on the inheritance of the type of the base class.)

   The keyword `public` is used to define a "is a" relationship. The child inherits the public and protected members of the inherited class and also inherits the type of the base class. `protected` and `private` are used to define a "has a" relationship. This makes the child inherit the public and protected members of the inherited class as protected and private, respectively and the child does not inherit the base class type.

- [x] 27. **Im Falle von Inheritance kann es zu slicing kommen?  Was ist dies und in welcher Situation tritt dieses Phaenomen?**
   (Inheritance can lead to slicing? What is this and in which situation does this phenomenon occur?)

   Yes. This happens when an instance of a SubClass is passed to a function expecting an instance of the base class. The function then uses the copy constructor of the base class and slices everything else that corresponds to the SubClass. In order to avoid this, we can pass the instance of the SubClass as a reference or a pointer. This can also occur during assignment.

- [x] 28. **Erklaeren sie den Begriff binding im Zusammenhang mit inheritance.**
   (Explain the term binding in the context of inheritance.)

   When you pass an instance of a SubClass to a function expecting an instance of the base class, even if it's by reference or pointer, the function will call the base class methods if needed, because those methods are binded to the base class. In order to solve this, you can declare the function virtual and it will decide during runtime which method to call, depending the case.

- [x] 29. **Erklaeren Sie die unterschliedlichen Arten von casts in C++.**
   (Explain the different types of casts in C ++.)

   - `static_cast<T>(o)` converts an object o into a given type T. Verified during compile time
   - `dynamic_cast<T>(o)` checks if o is of type T and returns NULL if it is not. Verified during run time
   - `reinterpret_cast<T>(o)` value of object o will be interpreted to be of type T. Not verified.


- [x] 30. **Erklaeren Sie das Liskov Substitution Principle.**
   (Explain the Liskov Substitution Principle.)

   Every function/program must work the same when it is invoked with a subclass instead of the expected class.

- [x] 31. **Wie funktioniert exception discrimination in C++?**
   (How does exception discrimination work in C ++?)

   By order of the catch clauses, as if it was an if, else statement. Just like in Python and Java.

- [x] 32. **C++ verfuegt im Gegensatz zu anderen Programmiersprachen ueber kein finally Schluesselwort.  Wieso ist dieses in C++ nicht notwendig?  Erklaeren Sie Ihre Antwort anhand eines Beispiels.**
   (Unlike other programming languages, C ++ does not have a finally keyword. Why is this not necessary in C ++? Explain your answer with an example.)

   Because try blocks in C++ invoke destructors in a deterministic way. When leaving the try block, it will deallocate memory associated with objects created inside the respective block.

- [ ] 33. **Erklaeren Sie Komplexitaetsgarantien der C++ Container vector, map, set, list in Bezug auf Einfuegen und den Zugriff auf einzelene Objekte (jeweils am Anfang, am Ende, beziehungsweise an einer bestimmten anderen Position).**
   (Explain complexity guarantees of the C ++ containers vector, map, set, list in terms of inserting and accessing individual objects (at the beginning, at the end, or at a certain other position).)

- [x] 34. **Welche Routine bzw. Routinen werden am Anfang eines jeden C++ Programmes ausgefuehrt?**
   (Which routine or routines are executed at the beginning of every C ++ program?)

   The main function.

- [x] 35. **Wozu dient static_assert?  Erklaeren Sie anhand eines Beispiels in welchem Zusammenhang es sinnvoll ist.**
   (What is static_assert for? Explain by way of example in what context it makes sense.)

   It works like `assert` but the assertion is verified in compile time. A possible use case would be to make sure that a buffer is initialized with a minimum value, for example:/
   ```
   template<typename T, int N>
     class Buffer {
     static_assert(N>16, "Buffer size too small");
   …
   };
   ```

- [x] 36. **C++ verfuegt seit C++11 ueber initializer lists.  Wozu dienen diese?  Wie werden Sie in der Standard Library verwendet?  Wie kann man diese selber verwenden?**
   (C ++ has been using C ++ 11 via initializer lists. What are these for? How are you used in the standard library? How can you use it yourself?)

   They represent a list of values and are usually used to accept a set of elements in the costructor or a function. They are used in the containers of the standard library in order to initialize them with a set of elements already inside. They can be used with the initializer_list<T> template and by using its iterator to access the given elements.

- [x] 37. **Erklaeren Sie wozu die Schluesselwoerter auto, decltype dienen.**
   (Explain what the keywords auto, decltype are for.)

   The keyword auto is to let the compiler infer the type from the assigned expression. It has to be determined during compile time.\
   The keyword decltype(e) returns the type of the expression e.

- [x] 38. **Wie kann seit C++11 ein thread gestartet werden und wie kann man anschliessend auf dessen Beendigung warten?**
   (How can a thread be started since C ++ 11 and how can you wait for it to finish?)

   To start them, they need to be passed a functor as an argument and they will be started immediately. You can use join to wait for the thread to finish.

- [x] 39. **Was sind variadic templates?  Wo finden diese in C++ Verwendung?**
   (What are variadic templates? Where do these find use in C ++?)

   These are templates that have an undefined number of arguments. The functions identifies the arguments automatically. It can be useful in functions that accepts an undefined number of arguments of different types, like `printf`

- [x] 40. **Welche Eigenschaften haben „templates“ und „inheritance“ gemein? Was ist ein fundamentaler (der fundamentale) Unterschied dieser beiden Mechanismen.**
   (What properties do "templates" and "inheritance" have in common? What is a fundamental (the fundamental) difference between these two mechanisms?)

   Both let you specialize to different cases but they are "orthogonal" between them. Inheritance specializes in a vertical fashion, going deeper and deeper with classes haveing a relation between them. Templates, on the other hand, specialize in a horizontal way, having different implementations in the same level of abstraction, where the code knows nothing about the other templates code. Also, inheritance provides runtime specialization and templates do it in compiler time.