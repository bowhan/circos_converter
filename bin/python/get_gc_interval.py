def get_gc_from_seq(seq):
    gc = 0
    total = 0
    for nt in seq:
        if nt == 'G' \
                or nt == 'C' \
                or nt == 'g' \
                or nt == 'c':
            gc += 1
            total += 1
        else:
            total += 1
    return float(gc) / total


def get_gc_from_fa(file, interval=1000):
    from Bio import SeqIO
    with open(file) as fh:
        for seqrec in SeqIO.parse(fh, "fasta"):
            i = 0
            j = 0
            length = len(seqrec)
            while i < length:
                j = i + interval if i + interval < length else length
                gc = get_gc_from_seq(seqrec[i:j])
                print("{}\t{}\t{}\t{}".format(seqrec.name, i, j, gc))
                i += interval


import sys, os

if os.path.exists(sys.argv[1]):
    get_gc_from_fa(sys.argv[1])

