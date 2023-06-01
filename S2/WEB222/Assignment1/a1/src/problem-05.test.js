const { normalizeDuration } = require('./solutions');

/**
 * 1. "1:30:0"
 * 2. "1h30m0s"
 *
 * In the first case, the values are separated by `:`.  In the second, the values
 * are followed by the unit (h, m, s).
 *
 * Valid Hour values are positive integers between 0 and 24.
 *
 * Valid Minute values are positive integers between 0 and 59.
 *
 * Valid Second values are positive integers between 0 and 59.
 *
 * Parse the value and return a new string in the following form:
 *
 * "(hours, minutes, seconds)"
 */

describe('Problem 5 - normalizeDuration() function', function () {
  test('a valid duration in the form h:m:s is returned as expected', function () {
    let duration = '24:59:59';
    expect(normalizeDuration(duration)).toBe('(24, 59, 59)');
  });

  test('a valid duration in the form Hh:Mm:Ss is returned as expected', function () {
    let duration = '0h1m2s';
    expect(normalizeDuration(duration)).toBe('(0, 1, 2)');
  });

  test('the hour value of a duration must be greater than 0', function () {
    expect(normalizeDuration('-1:2:3')).toBe(null);
    expect(normalizeDuration('-1h2m3s')).toBe(null);
  });

  test('the minute value of a duration must be greater than 0', function () {
    expect(normalizeDuration('1:-1:3')).toBe(null);
    expect(normalizeDuration('1h-1m3s')).toBe(null);
  });

  test('the second value of a duration must be greater than 0', function () {
    expect(normalizeDuration('1:1:-3')).toBe(null);
    expect(normalizeDuration('1h1m-3s')).toBe(null);
  });

  test('the hour value of a duration must be less than 25', function () {
    expect(normalizeDuration('25:2:3')).toBe(null);
    expect(normalizeDuration('25h2m3s')).toBe(null);
  });

  test('the minute value of a duration must be less than 60', function () {
    expect(normalizeDuration('1:60:3')).toBe(null);
    expect(normalizeDuration('1h60m3s')).toBe(null);
  });

  test('the second value of a duration must be less than 60', function () {
    expect(normalizeDuration('1:1:60')).toBe(null);
    expect(normalizeDuration('1h1m60s')).toBe(null);
  });
});
