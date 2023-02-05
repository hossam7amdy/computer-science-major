# Relational Algebra Problems from Database System Concepts, 5th edition

**database for this set**

```
group: Banck

Employee = {
person_name street city

    'hossam' '6th District' '6th of October'
    'ahmed' 'Dokki' 'Giza'
    'emad' 'Maadi' 'Cairo'
    'mostafa' 'Tanta' 'Gharbia'

}

Works = {
person_name company_name salary

    'hossam' 'First Bank Corporation' 13000
    'ahmed' 'First Bank Corporation' 9000
    'emad' 'First Bank Corporation' 31000
    'mostafa' 'Small Bank Corporation' 6000

}

Company = {
company_name city

    'First Bank Corporation' 'Maadi'
    'Small Bank Corporation' 'Giza'
    'American Academy' 'Maadi'
    'Fawry' '6th of October'
    'Masary' 'Giza'

}

Manager = {
person_name manager_name

    'emad' 'hossam'
    'ahmed' 'hossam'
    'mostafa' 'hossam'
    'hossam' null

}
```

## Answers

### Problem 2.6

- a) `π person_name (σ company_name='First Bank Corporation'(Works))`
- b) `π person_name,city
(σ company_name='First Bank Corporation'(Employee ⨝ Works))`
- c) `π person_name,street,city
(σ company_name='First Bank Corporation' ∧ salary > 10000
(Employee ⨝ Works))`
- d) `π person_name (σ Employee.city=Company.city (Employee ⟗ Company))`
- e) `π Company.company_name σ Company.city=temp.city (Company ⨯ ρ temp
(π company_name, city (σ company_name='Small Bank Corporation'(Company))))`

### Problem 2.6

- a) Because natural join eliminate duplicates (relation is a set of tuples)
- b) Instead we could use full outer join (⟗) or Cartesian product (⨯)
- c) `π customer_name, loan_number, amount, city (borrower ⨯ loan)`

### Problem 2.7

- a) `Works ← π person_name,company_name,salary*0.10
(σ company_name='First Bank Corporation'(Works))
∪
σ company_name ≠ 'First Bank Corporation'(Works)`
- b)
- c)

### Problem 2.8

### Problem 2.9

---

# Relational Division Operations

**Given these relations:**

- monkey_likes(name, food)
- monkey_foods(food)

| name    | food    |
| ------- | ------- |
| Bobo    | apples  |
| Bobo    | bananas |
| Jojo    | apples  |
| Jojo    | oranges |
| Jojo    | bananas |
| Lulu    | oranges |
| Lulu    | bananas |
| Guenter | apples  |
| Guenter | oranges |
| Guenter | bananas |
| Guenter | tofu    |

| food    |
| ------- |
| apple   |
| orange  |
| bananas |

- a)

- b)

- c)

---

# Query Optimization and Equivalence Rules

- a)

- b)

- c)

- d)

- e)

---

## Links

- [Use](https://dbis-uibk.github.io/relax/landing) to test your relation algebra queries
