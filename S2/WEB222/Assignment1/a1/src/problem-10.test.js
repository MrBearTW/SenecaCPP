const { buildQueryString } = require('./solutions');

// function buildQueryString(query, order, count, license) {

describe('Problem 10 - buildQueryString() function', function () {
  function assertQueryString(queryString, queryTerm, sortOrder, count) {
    let url = new URL(queryString, 'https://api.com');
    expect(url.searchParams.get('query_term')).toEqual(queryTerm);
    expect(url.searchParams.get('count')).toEqual(String(count));
    if (sortOrder === 'descending') {
      expect(url.searchParams.has('descending')).toBe(true);
    } else {
      expect(url.searchParams.has('ascending')).toBe(false);
    }
  }

  test('correct values produce an expected url', function () {
    let url = buildQueryString('butterfly', 'ascending', 50, 'cc-by');
    expect(typeof url).toEqual('string');
    assertQueryString(url, 'butterfly', 'ascending', 50);
  });

  test('query values are properly encoded on url', function () {
    let url = buildQueryString('butterfly with special characters:/\\{}<>[]}`"', 'ascending', 50);
    expect(typeof url).toEqual('string');
    assertQueryString(
      url,
      'butterfly with special characters:/\\{}<>[]}`"',
      'ascending',
      50,
      'cc-by'
    );
  });

  test('count below 10 throws but 10 works', function () {
    expect(() => buildQueryString('butterfly', 'ascending', 0)).toThrow();

    let url = buildQueryString('butterfly', 'ascending', 10);
    expect(typeof url).toEqual('string');
    assertQueryString(url, 'butterfly', 'ascending', 10);
  });

  test('count above 200 throws but 200 works', function () {
    expect(() => buildQueryString('butterfly', 'ascending', 201)).toThrow();

    let url = buildQueryString('butterfly', 'ascending', 200);
    expect(typeof url).toEqual('string');
    assertQueryString(url, 'butterfly', 'ascending', 200);
  });

  test('order can be `ascending`', function () {
    let url = buildQueryString('butterfly', 'ascending', 50);
    expect(typeof url).toEqual('string');
    assertQueryString(url, 'butterfly', 'ascending', 50);
  });

  test('order can be `descending`', function () {
    let url = buildQueryString('butterfly', 'descending', 50);
    expect(typeof url).toEqual('string');
    assertQueryString(url, 'butterfly', 'descending', 50);
  });

  test('order other than asc/desc throws', function () {
    expect(() => buildQueryString('butterfly', 'desc', 50, 'cc-by')).toThrow();
    expect(() => buildQueryString('butterfly', 'asc', 50, 'cc-by')).toThrow();
    expect(() => buildQueryString('butterfly', '', 200, 'cc-by')).toThrow();
  });
});
