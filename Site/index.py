#!/usr/bin/env python3


"""
Copyright 2015 Gu Zhengxiong <rectigu@gmail.com>
"""


from os import listdir
from os.path import isdir, dirname, join
from sys import argv
from string import ascii_lowercase
from itertools import groupby
from operator import itemgetter

from fn import F


def main():
    key = F(str.lower) << itemgetter(0)
    for arg in argv[1:]:
        if isdir(arg):
            many = sorted(listdir(arg), key=key)
            groups = groupby(many, key=key)
            dest = join(dirname(arg), 'one.html')
            with open(dest, 'w') as one:
                one.write(make_index(make_all(groups)))


def make_index(body):
    return """
<!doctype html>
<html>
  <head>
    <meta charset="utf-8" />
    <title>Lost SDK For Windows Security Researchers</title>
    <link rel="stylesheet" href="css/foundation.css" />
    <link rel="stylesheet" href="css/app.css" />
  </head>
  <body>
{}
    <script src="js/vendor/jquery.min.js"></script>
    <script src="js/vendor/what-input.min.js"></script>
    <script src="js/foundation.min.js"></script>
    <script src="js/app.js"></script>
  </body>
</html>
""".strip().format(body)


def make_all(groups):
    final = ''
    for letter, ones in groups:
         final += make_top(letter.upper(), sorted(ones))
    return """
    <ul role="tablist"
        class="accordion"
        data-accordion=""
        data-multi-expand="true"
        data-allow-all-closed="true">
{}
    </ul>
""".strip().format(final)


def make_top(top, names):
    return """
      <li class="accordion-item">
        <a role="tab" class="accordion-title" href="#">{}</a>
{}
      </li>
""".strip().format(top, ''.join([make_one(name) for name in names]))


def make_one(name):
    return """
        <div role="tabpanel"
             class="accordion-content"
             data-tab-content="">
          <a href="files/{}" target="content">{}</a>
        </div>
""".strip().format(name, name[:name.find('.')])


if __name__ == '__main__':
    main()
