CREATE TABLE Nations (
	Name varchar(20) NOT NULL,
	Domain varchar(3),
	Capital varchar(20),
	Latitude int,
	N_S char(1),
	Longitude int,
	E_W char(1),
	Interest varchar(20),
	PRIMARY KEY (Name)
	
);

INSERT INTO Nations VALUES ('Ireland', 'IE', 'Dublin', 52, 'N', 7, 'W', 'History');
INSERT INTO Nations VALUES ('Israel', 'IR', 'Jerusalem', 32, 'N', 35, 'E', 'History');
INSERT INTO Nations VALUES ('Italy', 'IT', 'Rome', 42, 'N', 12, 'E', 'Art');
INSERT INTO Nations VALUES ('Jamaica', 'JM', 'Kingston', 18, 'N', 77, 'W', 'Beach');
INSERT INTO Nations VALUES ('Japan', 'JP', 'Tokyo', 35, 'N', 143, 'E', 'Kabuki');
# XC INSERT INTO statement
INSERT INTO Nations VALUES ('China', 'CN', 'Beijing', 35, 'N', 105, 'E', 'History');

