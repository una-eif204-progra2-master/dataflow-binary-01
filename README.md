# Ejemplo de DataFlow con Archivos de Texto
El ejemplo se enfoca en crear un archivo de texto con los datos que estan definidos en el objeto persona.
## Librerias utilizadas
- [fstream](https://www.cplusplus.com/reference/fstream/fstream/?kw=fstream): Input/output stream class to operate on files.

### Write

```c++
// Create and open a text file
ofstream myFile(fileName, ios_base::app);
```

| member constant | opening mode                                                 |
| --------------- | ------------------------------------------------------------ |
| app             | (**app**end) Set the stream's position indicator to the end of the stream before each output operation. |
| ate             | (**at e**nd) Set the stream's position indicator to the end of the stream on opening. |
| binary          | (**binary**) Consider stream as binary rather than text.     |
| in              | (**in**put) Allow input operations on the stream.            |
| out             | (**out**put) Allow output operations on the stream.          |
| trunc           | (**trunc**ate) Any current content is discarded, assuming a length of zero on opening. |

### Read

#### Line By Line

```C++
// Use a while loop together with the getline() function to readByLine the file line by line
    while (getline (myReadFile, myTextLine)) {
        // Output the text from the file
        myText = myText + myTextLine + "\n\r";
    }
```

### Full Content

```c++
    content.assign((istreambuf_iterator<char>(myReadFile)),
                   (istreambuf_iterator<char>()));
```

 
