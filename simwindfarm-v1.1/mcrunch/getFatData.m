function fat=getFatData()

global Fatigue

if(isfield(Fatigue,'Damage'))
fat.damage=Fatigue.Damage;
else
    fat.damage={};
end

if(isfield(Fatigue,'File'))
    fat.rainflow=Fatigue.File.RF;
else
    fat.rainflow={};
end

end