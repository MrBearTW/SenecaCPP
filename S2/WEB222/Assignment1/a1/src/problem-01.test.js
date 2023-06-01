const { toCamelCase } = require('./solutions');

describe('Problem 1 - toCamelCase() function', function () {
  test('returns name unmodified if it needs no changes', function () {
    let result = toCamelCase('variable');
    expect(result).toBe('variable');
  });

  test('returns simple name in UpperCamelCase if requested', function () {
    let result = toCamelCase('variable', true);
    expect(result).toBe('Variable');
  });

  test('correctly converts variable_name to variableName', function () {
    let result = toCamelCase('variable_name');
    expect(result).toBe('variableName');
  });

  test('correctly converts variable_name to VariableName', function () {
    let result = toCamelCase('variable_name', true);
    expect(result).toBe('VariableName');
  });

  test('correctly deals with multiple _ in a name', function () {
    let result = toCamelCase('variable_name_with_many_underscores');
    expect(result).toBe('variableNameWithManyUnderscores');
  });

  test('correctly deals with multiple _ in a row', function () {
    let result = toCamelCase('variable___name_with_multiple____________underscores');
    expect(result).toBe('variableNameWithMultipleUnderscores');
  });
});
