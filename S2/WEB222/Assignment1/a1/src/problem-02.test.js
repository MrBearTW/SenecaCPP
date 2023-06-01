const { createMetaTag } = require('./solutions');

describe('Problem 2 - createMetaTag() function', function () {
  test('correct <meta> tag for author info, stripping double-quotes where appropriate', function () {
    let name = 'author';
    let content = 'Kim Lee';
    let result = createMetaTag(name, content);
    expect(result).toBe('<meta name=author content="Kim Lee">');
  });

  test('leading whitespace is removed before using values', function () {
    let name = '  author';
    let content = '                  Kim Lee';
    let result = createMetaTag(name, content);
    expect(result).toBe('<meta name=author content="Kim Lee">');
  });

  test('trailing whitespace is removed before using values', function () {
    let name = 'author ';
    let content = 'Kim Lee                             ';
    let result = createMetaTag(name, content);
    expect(result).toBe('<meta name=author content="Kim Lee">');
  });

  test('double-quotes around value are not optional when the value includes a space', function () {
    let name = 'name with space';
    let content = 'value with space';
    let result = createMetaTag(name, content);
    expect(result).toBe('<meta name="name with space" content="value with space">');
  });

  test('double-quotes around value are not optional when the value includes tab', function () {
    let name = 'name\twith\ttab';
    let content = 'value\twith\ttab\t';
    let result = createMetaTag(name, content);
    expect(result).toBe('<meta name="name\twith\ttab" content="value\twith\ttab">');
  });
});
