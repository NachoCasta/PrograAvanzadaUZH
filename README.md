# PrograAvanzadaUZH

## Preguntas Examen
- [x] 1. **Wie koennen Mitglieder einer Klasse („class members“) im Konstruktor initialisiert warden, unabhaengig davon ob diese Mitglieder ueber einen „default constructor“ verfuegen oder nicht?**
   (How can members of a class (class members) be initialized in the constructor, regardless of whether these members have a default constructor or not?)

   In the `:` section. This will initialize the members skipping the default constructor. Example:\
   `Fraction(int numerator, int denominator): n(numerator), d(denominator) { ... }`

- [ ] 2. **Wie kann man verhindern, daß die vom Compiler generierten Klassenartefakte versehentlich verwendet werden (mit und ohne Verwendung von C++11 Funktionalitaet)?**
   (How can you prevent the compiler-generated class artifacts from being inadvertently used (with and without the use of C ++ 11 functionality)?)

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

- [ ] 5. **Erklaeren Sie die Bedeutung des Schluesselwortes constexpr und in welcher Situation dieses sinnvollerweise eingesetzt werden kann.**
   (Explain the meaning of the keyword constexpr and in which situation it can be usefully used.)

- [x] 6. **Erklaeren Sie die Bedeutung des Schluesselwortes inline und wie dieses sinnvollerweise eingesetzt werden kann, insbesondere im Zusammenhang von Projekten, die aus mehreren Objektdateien bestehen (und auch insbesondere wenn „link-time optimization“ nicht zur Verfuegung steht).**
   (Explain the meaning of the keyword inline and how it can be reasonably used, especially in the context of projects that consist of several object files (and especially if "link-time optimization" is not available).)

   The inline keyword is used before a function declaration to create an "inline function". This has to be declared in a header file and the compiler will replace every call to this function with the function body, so that your program doesn't have to call the function all the time. It's very useful if you have a simple function that you use in many places but you don't want to copy and paste the same code all over your code

- [x] 7. **Unter welchen Umstaenden gehoeren templates und als inline deklarierte Funktionen in die Headerdatei (*.h) und unter welchen in die Implementierungsdatei (*.cc)? Erklaeren Sie weshalb.**
   (Under what circumstances do templates and inline declared functions belong in the header file (* .h) and under which in the implementation file (* .cc)? Explain why.)

  Under every circumstance templates and inline declared functions have to go in the header file, because the code needs to be known in compile time.

- [x] 8. **Erklaeren Sie die Bedeutung des Schluesselwortes friend und wo dieses sinnvollerweise eingesetzt werden kann.**
   (Explain the meaning of the keyword friend and where this can be meaningfully used.)

   It lets you declare another class or function as a friend, which lets them access private and protected members of the class where the friend declaration appears. One of the use cases would be when defining the std::istream and std::ostream operators. Another use case would be classes that have a close relationship to each other, for example: matrix and vector.

- [ ] 9. **Erklaeren Sie den Unterschied zwischen Pointer und Reference. Worauf ist insbesondere bei Objekten, die auf dem Stack liegen aufzupassen?**
   (Explain the difference between Pointer and Reference. What is especially important for watching objects that are on the stack?)

- [ ] 10. **Was ist der unterschied zwischen einer virtuellen und nicht virtuellen "member function" (Methode)?  Wozu dient die virtuelle Methodentabelle?**
   (What is the difference between a virtual and a non-virtual "member function" (method)? What is the virtual method table for?)

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

- [ ] 13. **Wie werden in C++ ueblicherweise benutzerdefinierte Ein- und Ausgaberoutinen implementiert?  Was ist im Fehlerfall zu beachten?**
   (How is custom input and output routines implemented in C ++? What should be considered in case of error?)

- [ ] 14. **Wie koennen Sie in C++ einen benutzerdefinierten Konversionsoperator implementieren?**
   (How can you implement a custom conversion operator in C ++?)

- [ ] 15. **Welche Arten von Polymorphismus gibt es?**
   (What types of polymorphism exist?)

- [ ] 16. **Was passiert in C++ (intern) wenn ein Template mit unterschiedlichen Templateparametern verwendet wird?  Was ist ein Vorteil dieser Implementierung?**
   (What happens in C ++ (internally) when a template with different template parameters is used? What is an advantage of this implementation?)

- [ ] 17. **Erklaeren Sie die Funktion von C++ Iteratoren?  Wie werden diese verwendet?  Was sind deren Eigenschaften?**
   (Explain the function of C ++ iterators? How are these used? What are their properties?)

- [ ] 18. **Was ist eine trait Klasse.**
   (What is a trait class.)

- [ ] 19. **Vergleichen Sie eine trait Klasse mit einer puren virtuellen Klasse („interface“).**
   (Compare a trait class with a pure virtual class ("interface").)

- [ ] 20. **Weshalb werden in C++ (wie auch in C) Headerdateien (``*``.h) benoetigt? Welche Artifakte gehoeren daher prinzipiell in die Headerdatei?**
   (Why are header files (``*`` .h) required in C ++ (as well as in C)? Which artifacts are therefore part of the header file?)

- [ ] 21. **Wozu wird der move constructor verwendet?**
   (What is the move constructor used for?)

- [ ] 22. **Erklaeren Sie das „copy and swap“ Idiom. Was sind dessen Vorteile?**
   (Explain the "copy and swap" idiom. What are its advantages?)

- [ ] 23. **Was ist ein function object?  Wie kann dieses sinnvoll verwendet werden? Was ist eine lambda function? Wie unterscheidet sich diese von einem function object?**
   (What is a function object? How can this be used meaningfully? What is a lambda function? How does this differ from a function object?)

- [ ] 24. **C++ erlaubt es statisch anhand von Typdefinitionen eines template parameters unterschiedliche Implementierungen einer Funktion auszuwaehlen (tag dispatching).  Erklaeren Sie den Mechanismus anhand eines Beispiels.**
   (C ++ allows the static selection of different implementations of a function based on type definitions of a template parameter (tag dispatching). Explain the mechanism with an example.)

- [ ] 25. **C++ erlaubt es statisch mittels SFINAE (Substitution Failure Is Not An Error) anahnd von Eigenschaften eines templates unterschiedliche Implementierungen einer Funktion auszuwaehlen).  Erklaeren Sie die Funktionsweise.**
   (C ++ allows you to statically select different implementations of a function using SFINAE (Substitution Failure Is Not An Error). Explain how it works.)

- [ ] 26. **Erklaeren Sie den unterschied zwischen „class Sub : [public, protected, private] Base“?  Was sind die Implikationen, insbesondere auch auf die Vererbung des Types der Basisklasse.**
   (Explain the difference between "class Sub: [public, protected, private] Base"? What are the implications, especially on the inheritance of the type of the base class.)

- [ ] 27. **Im Falle von Inheritance kann es zu slicing kommen?  Was ist dies und in welcher Situation tritt dieses Phaenomen?**
   (Inheritance can lead to slicing? What is this and in which situation does this phenomenon occur?)

- [ ] 28. **Erklaeren sie den Begriff binding im Zusammenhang mit inheritance.**
   (Explain the term binding in the context of inheritance.)

- [ ] 29. **Erklaeren Sie die unterschliedlichen Arten von casts in C++.**
   (Explain the different types of casts in C ++.)

- [ ] 30. **Erklaeren Sie das Liskov Substitution Principle.**
   (Explain the Liskov Substitution Principle.)

- [ ] 31. **Wie funktioniert exception discrimination in C++?**
   (How does exception discrimination work in C ++?)

- [ ] 32. **C++ verfuegt im Gegensatz zu anderen Programmiersprachen ueber kein finally Schluesselwort.  Wieso ist dieses in C++ nicht notwendig?  Erklaeren Sie Ihre Antwort anhand eines Beispiels.**
   (Unlike other programming languages, C ++ does not have a finally keyword. Why is this not necessary in C ++? Explain your answer with an example.)

- [ ] 33. **Erklaeren Sie Komplexitaetsgarantien der C++ Container vector, map, set, list in Bezug auf Einfuegen und den Zugriff auf einzelene Objekte (jeweils am Anfang, am Ende, beziehungsweise an einer bestimmten anderen Position).**
   (Explain complexity guarantees of the C ++ containers vector, map, set, list in terms of inserting and accessing individual objects (at the beginning, at the end, or at a certain other position).)

- [ ] 34. **Welche Routine bzw. Routinen werden am Anfang eines jeden C++ Programmes ausgefuehrt?**
   (Which routine or routines are executed at the beginning of every C ++ program?)

- [ ] 35. **Wozu dient static_assert?  Erklaeren Sie anhand eines Beispiels in welchem Zusammenhang es sinnvoll ist.**
   (What is static_assert for? Explain by way of example in what context it makes sense.)

- [ ] 36. **C++ verfuegt seit C++11 ueber initializer lists.  Wozu dienen diese?  Wie werden Sie in der Standard Library verwendet?  Wie kann man diese selber verwenden?**
   (C ++ has been using C ++ 11 via initializer lists. What are these for? How are you used in the standard library? How can you use it yourself?)

- [ ] 37. **Erklaeren Sie wozu die Schluesselwoerter auto, decltype dienen.**
   (Explain what the keywords auto, decltype are for.)

- [ ] 38. **Wie kann seit C++11 ein thread gestartet werden und wie kann man anschliessend auf dessen Beendigung warten?**
   (How can a thread be started since C ++ 11 and how can you wait for it to finish?)

- [ ] 39. **Was sind variadic templates?  Wo finden diese in C++ Verwendung?**
   (What are variadic templates? Where do these find use in C ++?)

- [ ] 40. **Welche Eigenschaften haben „templates“ und „inheritance“ gemein? Was ist ein fundamentaler (der fundamentale) Unterschied dieser beiden Mechanismen.**
   (What properties do "templates" and "inheritance" have in common? What is a fundamental (the fundamental) difference between these two mechanisms?)