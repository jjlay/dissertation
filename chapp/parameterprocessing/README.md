## Summary
A function for parsing command line parameters

## Usage
```c++
std::map<std::string, std::string> parameters(int argc, char *argv[]);
```

### Parameters
`argc` - The number of command line parameters passed to the `main` call.

`argv` - The command line parameters

### Returns
A standard template library [map](http://www.cplusplus.com/reference/map/map/) where the key value is the parameter and the value part of the map is the value of the parameter. In the event that the command line argument is a switch, the value is empty.

## Example

```C++
#include "parameters.h"

#include <map>

#include <string>
#include <iostream>


int main(int argc, char *argv[]) {

    auto p = parameters(argc, argv);

    for (auto v : p)
        std::cout << v.first << " :: " << v.second << std::endl;

    return 0;
}
```

```
[host]$ ./main.out  -alpha 0.1  -beta  -gamma 1.2
_EXECUTABLE :: ./main.out
alpha :: 0.1
beta ::
gamma :: 1.2
[host]$
```
