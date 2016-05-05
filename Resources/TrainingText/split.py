
import sys

if len(sys.argv) < 3:
    print("Usage: python ./split.py input.txt outputFileNameBase outputCounterStart")
    quit()

reload(sys)
sys.setdefaultencoding('utf8')
outputFileNameBase = sys.argv[2]
textBatch = ''
batchCounter = int(sys.argv[3])

with open(sys.argv[1], 'r') as inputFile:
    for line in inputFile:
        strippedLine = line.strip()
        if strippedLine != '\n' and strippedLine != '\r' and strippedLine != '\r\n' and strippedLine != '':
            lineNoBreaks = strippedLine.replace('\n', '').replace('\r', '')
            textBatch = textBatch + lineNoBreaks + '\n'
        else:
            outputFileName = outputFileNameBase + str(batchCounter) + '.txt'
            with open(outputFileName, "wb") as outputFile:
                outputFile.write(textBatch)
            textBatch = ''
            batchCounter += 1
