def maybe_space(s):
    return ' ' + s if s else ''

def is_all_capital(s):
    for c in s:
        if not c.isupper() and not c.isdigit():
            return False
    return True
