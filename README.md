# Template-cpp
A C++ project demonstrating object-oriented programming concepts through the implementation of custom data types (complex, rational, vector), a template-based 3x3 matrix class, and its specializations (null and identity matrices), along with custom exception handling.

This project showcases advanced C++ programming concepts including:
- Object-oriented programming (OOP)
- Template programming
- Operator overloading
- Custom exception handling

##  Features

- **Custom Classes:**
  - `complex`: Represents complex numbers.
  - `rational`: Represents rational numbers with numerator and denominator.
  - `vector`: Represents a 3D vector.
  
- **Template Matrix Class:**
  - `matrix33<T>`: A generic 3x3 matrix class for any type `T`.
  - `null33<T>`: A 3x3 matrix initialized to zero (null matrix).
  - `identity33<T>`: A 3x3 identity matrix.

- **Exception Handling:**
  - `mexception33`: Custom exception class to demonstrate error handling.
  - Throws an error when a rational number is created with a zero denominator.

##  Code Structure

- **Data Classes:** Defined for `complex`, `rational`, and `vector` types.
- **Matrix Templates:** Template class `matrix33<T>` supports any data type with overloaded `<<` for output.
- **Derived Classes:** Specialized `null33` and `identity33` matrices.
- **Main Function:** Demonstrates usage with:
  - Integer matrix
  - Float matrix
  - Complex number matrix
  - Rational number matrix
  - Vector matrix
  - Null matrix
  - Identity matrix
