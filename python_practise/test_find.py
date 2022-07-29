from curses.ascii import isdigit
import find
import pytest

def test_ispresent():
    assert find.ispresent('Al')

def test_nodigit():
    assert find.nodigit('N7')