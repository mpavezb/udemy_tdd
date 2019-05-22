# Test Doubles

## Types

- Dummy: Objects that can be passed around as necessary but do not have any type of test implementation and should never be used.
- Fake: These object generally have a simplified functional implementation of a particular interface that is adecuate for testing but not for production.
- Stub: These objects provide implementations with predefined answers that are suitable for the test.
- Spies: These objects provide implementations that record the values that were passed in so they can be used by the test.
- Mocks: These objects are pre-programmed to expect specific calls and parameters and can throw exceptions when necessary.


## Examples

### Dummy

Dummy objects expect to never be used nad will throw then called.

```cpp
class MyDummy: public MyInterface {
public:
    void someFunction() { throw std::exception("I should not be called!.")}
};
```

### Stub

Stubs expect to be called and return predefined data.
```cpp
class MyStub: public MyInterface {
public:
    int someFunction() { return 0; }
};
```

### Fake

Fake objects provide a simplified implementation of an inteface.
```cpp
class MyFake: public MyInterface {
public:
    void pushData(int data) { items.push_back(data); }
protected:
    std::vector<int> items;
};
```

### Spy

Spy objects save parameters that were passed into them so they can be analyzed by the test.
```cpp
class MySpy: public MyInterface {
public:
    int saved_param;
    void someFunction(int data) { saved_param = data; }
};
```

### Mock

Mock objects are the most intelligent.

They have setup expectations on how they will be called and throw exceptions if the those expectations are not met.
```cpp
class MyMock: public MyInterface {
public:
    void someFunction(int data) { 
        if (data != 0) {
            throw std::exception("I should not be called!.")
        }
    }
};
```
