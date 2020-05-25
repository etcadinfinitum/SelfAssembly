import static
import sys

def write_ruleset(rule):
    return '    { pairs: { { older: ' + label + ', newer: ' + label + '}, { older: ' + label + ', newer: ' + label + '}, }, },'

def write_rules():
    with open('output/sketch.ino', 'w') as outfile:
        outfile.write(static.beginning)

        outfile.write(static.end)

def main():
    pass

if __name__=='__main__':
    main()
