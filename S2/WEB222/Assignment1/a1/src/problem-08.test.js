const { generateLicenseBadge } = require('./solutions');

/*
 * '<a href="https://creativecommons.org/licenses/by-nc/4.0/"><img src="https://licensebuttons.net/l/by-nc/4.0/88x31.png" alt="Creative Commons Attribution-NonCommercial License"></a>'
 *
 * The URL is generated based on the license code:
 *
 * - remove the `CC-` prefix
 * - convert to lower case
 * - place the formatted license code within the URL https://creativecommons.org/licenses/[...here]/4.0/
 * - place the formatted license code within the Badge URL https://licensebuttons.net/l/[...here]/4.0/88x31.png
 */

describe('Problem 8 - generateLicenseBadge() function', function () {
  test('CC-BY license code produces correct badge', function () {
    let licenseCode = 'CC-BY';
    let result = generateLicenseBadge(licenseCode);
    expect(result).toBe(
      '<a href="https://creativecommons.org/licenses/by/4.0/"><img src="https://licensebuttons.net/l/by/4.0/88x31.png" alt="Creative Commons Attribution License"></a>'
    );
  });

  test('CC-BY-NC license code produces correct badge', function () {
    let licenseCode = 'CC-BY-NC';
    let result = generateLicenseBadge(licenseCode);
    expect(result).toBe(
      '<a href="https://creativecommons.org/licenses/by-nc/4.0/"><img src="https://licensebuttons.net/l/by-nc/4.0/88x31.png" alt="Creative Commons Attribution-NonCommercial License"></a>'
    );
  });

  test('CC-BY-SA license code produces correct badge', function () {
    let licenseCode = 'CC-BY-SA';
    let result = generateLicenseBadge(licenseCode);
    expect(result).toBe(
      '<a href="https://creativecommons.org/licenses/by-sa/4.0/"><img src="https://licensebuttons.net/l/by-sa/4.0/88x31.png" alt="Creative Commons Attribution-ShareAlike License"></a>'
    );
  });

  test('CC-BY-ND license code produces correct badge', function () {
    let licenseCode = 'CC-BY-ND';
    let result = generateLicenseBadge(licenseCode);
    expect(result).toBe(
      '<a href="https://creativecommons.org/licenses/by-nd/4.0/"><img src="https://licensebuttons.net/l/by-nd/4.0/88x31.png" alt="Creative Commons Attribution-NoDerivs License"></a>'
    );
  });

  test('CC-BY-NC-SA license code produces correct badge', function () {
    let licenseCode = 'CC-BY-NC-SA';
    let result = generateLicenseBadge(licenseCode);
    expect(result).toBe(
      '<a href="https://creativecommons.org/licenses/by-nc-sa/4.0/"><img src="https://licensebuttons.net/l/by-nc-sa/4.0/88x31.png" alt="Creative Commons Attribution-NonCommercial-ShareAlike License"></a>'
    );
  });

  test('CC-BY-NC-ND license code produces correct badge', function () {
    let licenseCode = 'CC-BY-NC-ND';
    let result = generateLicenseBadge(licenseCode);
    expect(result).toBe(
      '<a href="https://creativecommons.org/licenses/by-nc-nd/4.0/"><img src="https://licensebuttons.net/l/by-nc-nd/4.0/88x31.png" alt="Creative Commons Attribution-NonCommercial-NoDerivs License"></a>'
    );
  });

  test('Unknown license codes produces correct badge', function () {
    expect(generateLicenseBadge(null)).toBe(
      '<a href="https://choosealicense.com/no-permission/">All Rights Reserved</a>'
    );

    expect(generateLicenseBadge()).toBe(
      '<a href="https://choosealicense.com/no-permission/">All Rights Reserved</a>'
    );

    expect(generateLicenseBadge('copyright')).toBe(
      '<a href="https://choosealicense.com/no-permission/">All Rights Reserved</a>'
    );

    expect(generateLicenseBadge('Unknown')).toBe(
      '<a href="https://choosealicense.com/no-permission/">All Rights Reserved</a>'
    );
  });
});
