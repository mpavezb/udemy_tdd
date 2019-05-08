# udemy_tdd

## Test Driven Development Loop

```
    RED ----> GREEN ----> REFACTOR --
     |______________________________|
     
     RED      Phase: Write a Simple and Failing Unit Test.
     GREEN    Phase: Make the Test Pass.
     REFACTOR Phase: Clean up code. 
```  
Each Loop cycle should only have a duration of a few minutes.
    
## 3 Laws of TDD

1. Never write production code without a related unit test.
2. Just write 1 test at a time.
3. Write only required production code to make the test pass.

## Best Practices

- Always do the next simplest test case:
  - We can gradually increase the complexity.
  - Dont force complex cases and funcitonalities.
  - Avoid bad design desitions.

- Always use descriptive test names:
  - Code is read a lot more times after.
  - Unit test are the best documentation.
  - Test suites should the component (class/function) under test, and the test names should describe the tested functionality.
  
- Keep the tests fast.
  - Fast building and execution.
  - Avoid console output.
  - Mock out slow components.
  
- Use code coverage tools.
  - Identify holes in the suite.

- Run tests multiple times and in a random order.
  - Avoid intermittent failures.
  - Avoid dependencies between tests.
