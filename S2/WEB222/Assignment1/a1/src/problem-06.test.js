const { formatDurations } = require('./solutions');

describe('Problem 6 - formatDurations()', function () {
  test('a single duration is valid', function () {
    let result = formatDurations('4:16:24');
    expect(result).toBe('((4, 16, 24))');
  });

  test('valid durations of the form h:m:s should be formatted correctly in a list', function () {
    let result = formatDurations('4:16:24', '4:16:25', '4:16:26');
    expect(result).toBe('((4, 16, 24), (4, 16, 25), (4, 16, 26))');
  });

  test('valid durations of the form HhMmSs should be formatted correctly in a list', function () {
    let result = formatDurations('4h16m24s', '4h16m25s', '4h16m26s');
    expect(result).toBe('((4, 16, 24), (4, 16, 25), (4, 16, 26))');
  });

  test('invalid durations are skipped', function () {
    let result = formatDurations('4h16m24s', '60h60m60s', '100:100:100', '4h16m25s');
    expect(result).toBe('((4, 16, 24), (4, 16, 25))');
  });

  test('if all values are invalid, an empty list is returned', function () {
    let result = formatDurations('60h60m60s', '100:100:100');
    expect(result).toBe('()');
  });
});
