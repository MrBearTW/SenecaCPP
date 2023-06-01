const { typeFromFilename } = require('./solutions');

describe('Problem 7 - typeFromFilename() function', function () {
  test('correct type for TXT extension', function () {
    expect(typeFromFilename('doc.txt')).toEqual('text');
  });

  test('correct type for RTF extension', function () {
    expect(typeFromFilename('doc.rtf')).toEqual('text');
  });

  test('correct type for DOC extensions', function () {
    expect(typeFromFilename('document.doc')).toEqual('text');
    expect(typeFromFilename('document.docx')).toEqual('text');
  });

  test('correct type for JPEG extensions', function () {
    expect(typeFromFilename('photo.jpg')).toEqual('image');
    expect(typeFromFilename('photo.jpeg')).toEqual('image');
  });

  test('correct type for GIF extension', function () {
    expect(typeFromFilename('animation.gif')).toEqual('image');
  });

  test('correct type for BMP extension', function () {
    expect(typeFromFilename('graphic.bmp')).toEqual('image');
  });

  test('correct type for Icon extensions', function () {
    expect(typeFromFilename('favicon.ico')).toEqual('image');
    expect(typeFromFilename('cursor.cur')).toEqual('image');
  });

  test('correct type for PNG extension', function () {
    expect(typeFromFilename('photo.png')).toEqual('image');
  });

  test('correct type for SVG extension', function () {
    expect(typeFromFilename('chart.svg')).toEqual('image');
  });

  test('correct type for WEBP extension', function () {
    expect(typeFromFilename('photo.webp')).toEqual('image');
  });

  test('correct type for MP3 extension', function () {
    expect(typeFromFilename('music.mp3')).toEqual('audio');
  });

  test('correct type for WAV extension', function () {
    expect(typeFromFilename('sound.wav')).toEqual('audio');
  });

  test('correct type for MP4 extension', function () {
    expect(typeFromFilename('video.mp4')).toEqual('video');
  });

  test('correct type for WEBM extension', function () {
    expect(typeFromFilename('video.webm')).toEqual('video');
  });

  test('correct type for JSON extension', function () {
    expect(typeFromFilename('data.json')).toEqual('data');
  });

  test('correct type for MEPG extension', function () {
    expect(typeFromFilename('data.mpeg')).toEqual('video');
  });

  test('correct type for CSV extension', function () {
    expect(typeFromFilename('data.csv')).toEqual('spreadsheet');
  });

  test('correct type for XLS extension', function () {
    expect(typeFromFilename('data.xls')).toEqual('spreadsheet');
  });

  test('correct type for TTF extension', function () {
    expect(typeFromFilename('data.ttf')).toEqual('font');
  });

  test('correct type for WOFF extension', function () {
    expect(typeFromFilename('data.woff')).toEqual('font');
  });

  test('correct type for ZIP extension', function () {
    expect(typeFromFilename('data.zip')).toEqual('archive');
  });

  test('correct type for AVI extension', function () {
    expect(typeFromFilename('data.avi')).toEqual('video');
  });

  test('correct type for unknown extensions', function () {
    expect(typeFromFilename('file.exe')).toEqual('binary');
    expect(typeFromFilename('library.dll')).toEqual('binary');
  });

  test('absolute Unix file paths give correct type', function () {
    expect(typeFromFilename('/public/site/www/cat.jpg')).toEqual('image');
  });

  test('absolute Windows file paths give correct type', function () {
    expect(typeFromFilename('C:\\Documents\\Seneca\\WEB222\\students.xls')).toEqual('spreadsheet');
  });

  test('spaces in path give correct type', function () {
    expect(typeFromFilename('/this path/has quite a/few spaces/doc.txt')).toEqual('text');
  });

  test('periods in path give correct type', function () {
    expect(typeFromFilename('/this.path/has.quite.a/few.periods/dog.png')).toEqual('image');
  });

  test('relative path gives correct type', function () {
    expect(typeFromFilename('../names.json')).toEqual('data');
  });

  test('filename with no extension should give unknown type', function () {
    expect(typeFromFilename('/this/file/has/no/extension')).toEqual('unknown');
  });

  test('filename with unexpected extension should give unknown type', function () {
    expect(typeFromFilename('/this/file/has/an/unknown/extension.cgi')).toEqual('unknown');
  });
});
