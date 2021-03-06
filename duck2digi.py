# (Original) https://github.com/toxydose/Duckyspark/
# This file is modified from the original repo.
from tempfile import NamedTemporaryFile
import shutil, sys
spacing = 2

SPECIAL_BUTTONS = {'CONTROL_RIGHT': 'MOD_CONTROL_RIGHT',
                   'CONTROL_LEFT':  'MOD_CONTROL_LEFT',
                   'CONTROL':       'MOD_CONTROL_LEFT',
                   'CTRL_RIGHT':    'MOD_CONTROL_RIGHT',
                   'CTRL_LEFT':     'MOD_CONTROL_LEFT',
                   'CTRL':          'MOD_CONTROL_LEFT',

                   'SHIFT_RIGHT':   'MOD_SHIFT_RIGHT',
                   'SHIFT_LEFT':    'MOD_SHIFT_LEFT',
                   'SHIFT':         'MOD_SHIFT_LEFT',

                   'ALT_RIGHT':     'MOD_ALT_RIGHT',
                   'ALT_LEFT':      'MOD_ALT_LEFT',
                   'ALT':           'MOD_ALT_LEFT',

                   'GUI_RIGHT':     'MOD_GUI_RIGHT',
                   'GUI_LEFT':      'MOD_GUI_LEFT',
                   'GUI':           'MOD_GUI_LEFT',
                   'WINDOWS':       'MOD_GUI_LEFT'}

# menu = Shift + F10
BUTTONS = {'a': 'KEY_A',
           'b': 'KEY_B',
           'c': 'KEY_С',
           'd': 'KEY_D',
           'e': 'KEY_E',
           'f': 'KEY_F',
           'g': 'KEY_G',
           'h': 'KEY_H',
           'i': 'KEY_I',
           'j': 'KEY_J',
           'k': 'KEY_K',
           'l': 'KEY_L',
           'm': 'KEY_M',
           'n': 'KEY_N',
           'o': 'KEY_O',
           'p': 'KEY_P',
           'q': 'KEY_Q',
           'r': 'KEY_R',
           's': 'KEY_S',
           't': 'KEY_T',
           'u': 'KEY_U',
           'v': 'KEY_V',
           'w': 'KEY_W',
           'x': 'KEY_X',
           'y': 'KEY_Y',
           'z': 'KEY_Z',

           'F1': 'KEY_F1',
           'F2': 'KEY_F2',
           'F3': 'KEY_F3',
           'F4': 'KEY_F4',
           'F5': 'KEY_F5',
           'F6': 'KEY_F6',
           'F7': 'KEY_F7',
           'F8': 'KEY_F8',
           'F9': 'KEY_F9',
           'F10': 'KEY_F10',
           'F11': 'KEY_F11',
           'F12': 'KEY_F12',

           'LEFTARROW':     'KEY_ARROW_LEFT',
           'RIGHTARROW':    'KEY_ARROW_RIGHT',
           'UPARROW':       'KEY_ARROW_UP',
           'DOWNARROW':     'KEY_ARROW_DOWN',
           'LEFT':          'KEY_ARROW_LEFT',
           'RIGHT':         'KEY_ARROW_RIGHT',
           'UP':            'KEY_ARROW_UP',
           'DOWN':          'KEY_ARROW_DOWN',

           'DELETE':        'KEY_DELETE',
           'DEL':           'KEY_DELETE',
           'PRINTSCREEN':   'KEY_PRT_SCR',
           'TAB':           'KEY_TAB',
           'ESCAPE':        'KEY_ESC',
           'SPACE':         'KEY_SPACE',
           'ENTER':         'KEY_ENTER'}

# arguments
payload_input = ''
payload_len = 0
if len(sys.argv) == 2:
    try:
        payload_input = open(sys.argv[1], "r")
        payload_len = len(open(sys.argv[1], "r").readlines())
    except IOError:
        error_reason = ('File "' + sys.argv[1] + '" does not exist!\n')
        print(f'ERROR! -h or --help for help\n{error_reason}')
        exit()
elif len(sys.argv) == 3:
    try:
        payload_input = open(sys.argv[1], "r")
        payload_len = len(open(sys.argv[1], "r").readlines())
    except IOError:
        error_reason = ('File "' + sys.argv[1] + '" does not exist!\n')
        print(f'ERROR! -h or --help for help\n{error_reason}')
        exit()
elif len(sys.argv) > 3:
    error_reason = 'Too much Arguments'
    print(f'ERROR! -h or --help for help\n{error_reason}')
    exit()
else:
    try:
        payload_input = open('payload.txt', "r")
        payload_len = len(open('payload.txt', "r").readlines())
    except FileNotFoundError:
        print('\nERROR: Payload file "payload.txt" was not found')
        exit()

def main():
    tempfile = NamedTemporaryFile(mode='a+', delete=False, newline='')
    coding(tempfile)

def coding(tempfile):
    tempfile.write(f'#include "DigiKeyboard.h"\n#define KEY_ESC     41\n#define KEY_TAB     43\n#define KEY_PRT_SCR 70\n#define KEY_DELETE  76\n#define KEY_ARROW_RIGHT 0x4F\n#define KEY_ARROW_DOWN  0x51\n#define KEY_ARROW_UP    0x52\n\n')
    tempfile.write("void setup() {\n" + f'{" "*spacing}pinMode(1, OUTPUT);\n{" "*spacing}DigiKeyboard.delay(5000);\n{" "*spacing}DigiKeyboard.sendKeyStroke(0);')

    for i in range(payload_len):
        line = payload_input.readline().replace('\n', '')
        if len(line) < 1:
            tempfile.write('')
        else:
            if 'REM' in line:
                tempfile.write(f'\n{" "*spacing}// {line.replace("REM ", "")}')
            else:
                if 'DELAY' in line:
                    tempfile.write(f'\n{" "*spacing}DigiKeyboard.' + line.replace("DELAY", "delay(").replace(" ", "") + ');')
                elif 'STRING' in line:
                    tempfile.write(f'\n{" "*spacing}DigiKeyboard.' + line.replace('"', '")); DigiKeyboard.print(char(34)); DigiKeyboard.print(F("')
                        .replace('\\', '")); DigiKeyboard.print(char(92)); DigiKeyboard.print(F("').replace('STRING ', 'print(F("') + '"));')
                elif 'MENU' in line:
                    line = 'KEY_F10'
                    mod = 'MOD_SHIFT_LEFT'
                    tempfile.write(f'\n{" "*spacing}DigiKeyboard.sendKeyStroke({str(line)},{mod});')
                else:
                    mod = ''
                    for key in SPECIAL_BUTTONS.keys():
                        if key in line:  # order in keys is important
                            line = line.replace(key, '')
                            mod += SPECIAL_BUTTONS.get(key) + ' | '
                    mod += '0'

                    line = line.replace(' ', '')
                    if line in BUTTONS.keys():
                        line = BUTTONS.get(line)
                    else:
                        line = '0'
                    tempfile.write(f'{" "*spacing}DigiKeyboard.sendKeyStroke({str(line)},{mod});')

            if len(line) < 1:
                tempfile.write('')

    tempfile.write("\n}\n\nvoid loop() {\n" + f'{" "*spacing}digitalWrite(1, HIGH);\n{" "*spacing}delay(1000);\n{" "*spacing}digitalWrite(1, LOW);\n{" "*spacing}delay(1000);' + "\n}")
    tempfile.close()
    payload_input.close()
    shutil.move(tempfile.name, f'{sys.argv[2]}.ino')

if __name__ == '__main__':
    main()