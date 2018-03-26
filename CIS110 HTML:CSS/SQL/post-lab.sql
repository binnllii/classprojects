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
INSERT INTO Nations VALUES ('Australia', 'AU', 'Canberra', 37, 'S', 148, 'E', 'Beach');
INSERT INTO Nations VALUES ('Bahamas', 'BS', 'Nassau', 25, 'N', 78, 'W', 'Beach');
INSERT INTO Nations VALUES ('Barbados', 'BB', 'Bridgetown', 13, 'N', 59, 'W', 'Beach');
INSERT INTO Nations VALUES ('Belize', 'BZ', 'Belmopan', 17, 'N', 89, 'W', 'Beach');
INSERT INTO Nations VALUES ('Bermuda', 'BM', 'Hamilton', 32, 'N', 64, 'W', 'Beach');
INSERT INTO Nations VALUES ('Falkland Is', 'FK', 'Stanley', 51, 'S', 58, 'W', 'Nature');
INSERT INTO Nations VALUES ('Finland', 'Fl', 'Helsinki', 61, 'N', 26, 'E', 'Nature');
INSERT INTO Nations VALUES ('Greenland', 'GL', 'Nuuk', 72, 'N', 40, 'W', 'Nature');
INSERT INTO Nations VALUES ('Iceland', 'IS', 'Reykjavic', 65, 'N', 18, 'W', 'Geysers');
INSERT INTO Nations VALUES ('Norway', 'NO', 'Oslo', 60, 'N', 10, 'E', 'Vikings');

 SELECT * FROM Nations WHERE Name LIKE 'C%';
SELECT * FROM Nations WHERE Name LIKE '%land'; 
SELECT * FROM Nations WHERE Name LIKE '%w%'; 
SELECT * FROM Nations WHERE name LIKE '_____';

SELECT COUNT(*) FROM Nations  
WHERE Interest = 'History';
SELECT COUNT(*) FROM Nations; 

SELECT*FROM Nations WHERE (N_S='N' AND Interest='Beach')
UPDATE Nations SET Interest = 'Reggae' WHERE Name = 'Jamaica';
DELETE FROM Nations WHERE Name = 'Jamaica';








