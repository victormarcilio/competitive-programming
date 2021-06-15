//https://app.codesignal.com/company-challenges/spacex/z7JxdermwNBpomh8q
string cpuEmulator(vector<string> subroutine) {
    vector<unsigned int> registers(43);
    for(int i = 0; i < subroutine.size(); i++)
    {
        string& cmd = subroutine[i];
        string inst = cmd.substr(0, 3);
        if(inst == "DEC") 
            registers[stoi(cmd.substr(5))]--;
        else if(inst == "INC")
            registers[stoi(cmd.substr(5))]++;
        else if(inst == "INV")
            registers[stoi(cmd.substr(5))] = ~registers[stoi(cmd.substr(5))];
        else if(inst == "ADD")
        {
            int r1 = stoi(cmd.substr(5, 2));
            int r2 = stoi(cmd.substr(9));
            registers[r1] += registers[r2];
        }
        else if(inst == "JZ ")
        {
            if(!registers[0])
                i = stoi(cmd.substr(3)) - 2;
        }
        else if(inst == "JMP")
            i = stoi(cmd.substr(4)) - 2;
        else if(inst == "MOV")
        {
            if(cmd[4] == 'R')
            {
                int r1 = stoi(cmd.substr(5, 2));
                int r2 = stoi(cmd.substr(9));
                registers[r2] = registers[r1];
            }
            else
            {
                smatch sm;
                regex e("MOV ([0-9]+),R([0-9]+)");
                regex_match(cmd, sm, e);
                unsigned int d = stol(sm[1]);
                int r2 = stoi(sm[2]);
                registers[r2] = d;
            }
        }
    }
    return to_string(registers[42]);
}
