# Ejemplo de DataFlow con Archivos de Binarios
El ejemplo se enfoca en crear un archivo de binario con los datos que estan definidos en el objeto persona.
## Librerias utilizadas
- [fstream](https://www.cplusplus.com/reference/fstream/fstream/?kw=fstream): Input/output stream class to operate on files.

## **Unformatted Operations (binary files)**

- When data is stored in a file in the binary format, reading and writing data is faster because no time is lost in converting the data from one format to another format. Such files are called binary files. This following program explains how to create binary files and also how to read, write, search, delete and modify data from binary files.
- The class `ios_base` is a multipurpose class that serves as the base class for all I/O stream classes.

Member types and constants, stream open mode type:

| Constant | Explanation |
| --- | --- |
| app | seek to the end of stream before each write |
| binary | open in binary mode |
| in | open for reading |
| out | open for writing |
| trunc | discard the contents of the stream when opening |
| ate | seek to the end of stream immediately after open |

## **File size and indexation**

In C++, files are considered a stream or an array of uninterpreted bytes, each byte can also be considered a `char`, with the file contents considered as a char array: `(char *)myFile`.

The "array" of bytes stored in a file is indexed from zero to len-1, where len is the total number of bytes in the entire file.

## ****Opening Files****

There are two main ways of opening files in binary mode:

1. Set a file name and necessary flags in the constructor when declaring the object.

```cpp
ifstream myReadFile(filename, ios::in | ios::binary);

```

1. Declare a stream object and use the `open` method to set the file name and necessary flags.

```cpp
ifstream myFile;
myFile.open ("data2.dat", ios::out | ios::binary);

```

There are two main flags that need to be used when manipulating binary files:

1. The i/o mode `ios::in` or `ios::out`
2. The binary mode `ios::binary`

## **Read**

The `read` method extracts a given number of bytes from the stream, and places them into the memory pointed to by the first parameter.

```cpp
Person person;

std::string filename = "people.dat";
ifstream inFile;
inFile.open(filename, ios::in | ios::binary);

inFile.read((char*)&person, sizeof(person));

cout << person.toString << std::endl;

inFile.close();

```

### **Write**

The write member function writes a given number of bytes on the given stream, starting at the position of the "put" pointer.

```cpp
Person person1 = Person("Julio");

std::string filename = "people.dat";
ofstream outFile;
outFile.open(filename, ios::out | ios::binary);

outFile.write((char *)&person1, sizeof(person1));
outFile.close();
```

## **Accessing file positions**

Each open file will have a "get" and a "put" pointer, these store a position in the file, and are part of the stream object.

### **The GET pointer**

It is the current reading position, the index of the next byte that will be read from the file.

The get pointer can be repositioned with the `istream& seekg(streampos pos)` method.

To return the index of the get pointer on a given stream use `istream& tellg()`.

```cpp
Person person;

std::string filename = "people.dat";
ifstream inFile;
inFile.open(filename, ios::binary);

inFile.seekg (sizeof(person),ios::beg);
// Reading the second person in the fileinFile.read((char*)&person, sizeof(person));

cout << person.toString << std::endl;

inFile.close();

```

### **The PUT pointer**

The put pointer can be repositioned with the `ostream& seekp(streampos pos)` method.

To return the index of the put pointer on a given stream use `istream& tellp()`.

```cpp
Person person;

std::string filename = "people.dat";
ofstream outFile;
outFile.open(filename, std::ios::binary | std::ios::app);

std::cout << "Adding in position: " << outFile.tellg() << " byte." << std::endl;
// Adding to the end of the file.outFile.write((char*)&person, sizeof(person));

outFile.close();
``` 
