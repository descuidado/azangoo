f = open('raw_input.txt', 'r')
line = f.readline()
d = open('data.txt', 'wb')
while line != '':
    line = f.readline()
    linelist = line.split()
    try:
        sobh = linelist[3]
        zohr = linelist[5]
        shab = linelist[7]
        sobh = sobh.split(":")
        zohr = zohr.split(":")
        shab = shab.split(":")
        sobh_h = int(sobh[0])
        sobh_m = int(sobh[1])
        sobh_s = int(sobh[2])
        zohr_h = int(zohr[0])
        zohr_m = int(zohr[1])
        zohr_s = int(zohr[2])
        shab_h = int(shab[0])
        shab_m = int(shab[1])
        shab_s = int(shab[2])
        d.write(sobh_h.to_bytes())
        d.write(sobh_m.to_bytes())
        d.write(sobh_s.to_bytes())
        d.write(zohr_h.to_bytes())
        d.write(zohr_m.to_bytes())
        d.write(zohr_s.to_bytes())
        d.write(shab_h.to_bytes())
        d.write(shab_m.to_bytes())
        d.write(shab_s.to_bytes())
    except:
        pass
f.close()
print("DONE!")
