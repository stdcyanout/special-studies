program partion;

type matrix = array[1..20, 1..20] of integer;
var a, ta : matrix;
    m, n, i, j : integer;
    min, tp : integer;
procedure block(a : matrix; h, k, c : integer);
    var l : integer;
    
begin
    c := c + 1;
    if c < min then
        begin
            l := 0;
            while (h + l <= m) and (k + l <= n) and (a[h + l, k] = 0) do
                begin
                    l := l + 1;
                    for i := 0 to l - 1 do
                        for j := 0 to l - 1 do
                            a[h + i, k + j] := l;
            if (h + l <= m) and (a[h + l, k] = 0) then
                block(a, h + l, k, c)
        end;
    if (h + l = m + 1) or (a[h + l, k] <> 0) then
        begin
            while (a[h, k] <> 0) and (k <= n) do
                begin
                    h := h + a[h, k];
                    if h = m + 1 then
                        begin
                            h := 1;
                            k := k + 1;
                        end
                end;
            if k <= n then block(a, h, k, c)
            else
                begin
                    if c < min then
                        begin
                            min := c;
                            ta := a;
                        end
                end
        end
    end
end;
                
function f(a, b : integer) : integer;
var q, r, sum : integer;
begin
    sum := 0;
    while b <> 0 do
        begin
            q := a div b;
            r := a mod b;
            sum := sum + q;
            a := b;
            b := r;
        end;
    f := sum;
end;

begin {main}
    for j := 1 to n do
        for i := 1 to m do
            a[i, j] := 0;

readln(n); readln(m);
    tp := f(m, n);
    writeln('F = ', tp);
    min := tp;
    block(a, 1, 1, 0);
    if min = tp then
        writeln('NEVER BETTER')
    else    
    begin
        writeln('MIN = ', min);
        writeln('THE MATRIX IS');
        writeln;
        for j := 1 to n do
            begin
                for i := 1 to m do
                    write(ta[i, j] : 3);
                writeln
            end
    end
end.