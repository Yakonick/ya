CREATE DATABASE IF NOT EXISTS Tour;
USE Tour;
/*---------------------------------------------
 				CREATING TABLES
 --------------------------------------------*/
CREATE TABLE Person(
    Person_ID         INTEGER      NOT NULL,
    Last_Name	      VARCHAR(20)  NOT NULL,
    First_Name	      VARCHAR(20)  NOT NULL,
    Date_birth		  DATE		   NOT NULL,
    Phone	      VARCHAR(15)  UNIQUE NOT NULL,
    Address	      VARCHAR(50)  NOT NULL,
    Regular 	  INTEGER		DEFAULT 0			NOT NULL,
CONSTRAINT Person_Is_Regular CHECK (Regular in (0,1)),   
CONSTRAINT Person_PK PRIMARY KEY (Person_ID)
);

CREATE TABLE OrderT(
    Order_ID                      INTEGER         NOT NULL,
    Person_ID                     INTEGER         NOT NULL,
    Tour_ID                    	  INTEGER         NOT NULL,
    Price                         INTEGER         NOT NULL,
    Type_of_payment_ID            INTEGER         NOT NULL,
    Time_Order                    DATETIME        NOT NULL,
    Is_Done	                	  INTEGER       DEFAULT 0           NOT NULL,
    Comments                      VARCHAR(50),
CONSTRAINT Order_Is_Done CHECK (Is_Done in (0,1)),
CONSTRAINT Order_PK PRIMARY KEY (Order_ID)
)
;

CREATE TABLE Type_of_payment(
	Type_of_payment_ID            INTEGER         NOT NULL,
	Type_of_pay				      VARCHAR(30)     NOT NULL,
CONSTRAINT Type_of_payment_PK PRIMARY KEY (Type_of_payment_ID)	
)
;

CREATE TABLE Tour(
	Tour_ID							INTEGER			NOT NULL,
	Tour_type_ID					INTEGER			NOT NULL,
	Hotel_ID						INTEGER			NOT NULL,			
	Date_Tour_Start					DATETIME		NOT NULL,
	Date_Tour_End					DATETIME		NOT NULL,
CONSTRAINT Tour_PK PRIMARY KEY (Tour_ID)	
)
;

CREATE TABLE Type_of_Tour(
	Tour_type_ID            		INTEGER         NOT NULL,
	Tour_type				        VARCHAR(15)     NOT NULL,
CONSTRAINT Tour_type_PK PRIMARY KEY (Tour_type_ID)
)
;

CREATE TABLE Base_of_Countries(
	Country_ID						INTEGER         NOT NULL,
	Country							VARCHAR(20)     NOT NULL,
CONSTRAINT Country_PK PRIMARY KEY (Country_ID)
)
;

CREATE TABLE Base_of_Localities(
	Locality_ID						INTEGER			NOT NULL,
	Locality						VARCHAR(50)     NOT NULL,
	Country_ID						INTEGER         NOT NULL,
CONSTRAINT Locality_PK PRIMARY KEY (Locality_ID)	
)
;

CREATE TABLE Hotel(
	Hotel_ID						INTEGER			NOT NULL,
	Hotel_name						VARCHAR(30)		NOT NULL,
	Hotel_type						INTEGER			NOT NULL,
	Locality_ID						INTEGER			NOT NULL,
	Phone	      					VARCHAR(15)		UNIQUE NOT NULL,
    Address	      					VARCHAR(50)		NOT NULL,
CONSTRAINT Hotel_PK PRIMARY KEY (Hotel_ID)    
)
;


/*---------------------------------------------
 			CREATING FOREIGN KEYS
 --------------------------------------------*/

ALTER TABLE OrderT ADD CONSTRAINT FK_OrderT_Person
	FOREIGN KEY (Person_ID)
	REFERENCES Person(Person_ID);

ALTER TABLE OrderT ADD CONSTRAINT FK_OrderT_Tour
	FOREIGN KEY (Tour_ID)
	REFERENCES Tour(Tour_ID);

ALTER TABLE OrderT ADD CONSTRAINT FK_OrderT_Payment
	FOREIGN KEY (Type_of_payment_ID)
	REFERENCES Type_of_payment(Type_of_payment_ID);

ALTER TABLE Tour ADD CONSTRAINT FK_Tour_Type
	FOREIGN KEY (Tour_type_ID)
	REFERENCES Type_of_Tour(Tour_type_ID);

ALTER TABLE Tour ADD CONSTRAINT FK_Tour_Hotel
	FOREIGN KEY (Hotel_ID)
	REFERENCES Hotel(Hotel_ID);

ALTER TABLE Base_of_Localities ADD CONSTRAINT FK_Locality_Country
	FOREIGN KEY (Country_ID)
	REFERENCES Base_of_Countries(Country_ID);

ALTER TABLE Hotel ADD CONSTRAINT FK_Hotel_Locality
	FOREIGN KEY (Locality_ID)
	REFERENCES Base_of_Localities(Locality_ID);


/*---------------------------------------------
 				INSERT DATA
 --------------------------------------------*/

INSERT INTO Person(Person_ID,Last_Name,First_Name,Date_birth,Phone,Address,Regular) VALUES (1, 'Юсупов', 'Владимир', '1998-12-10', '+79179144444', 'ул. Пушкина, д. Колотушкина корпус Кукушкина', 1);
INSERT INTO Person(Person_ID,Last_Name,First_Name,Date_birth,Phone,Address,Regular) VALUES (2, 'Королев', 'Егор', '1998-02-01', '+79179334444', 'ул. Чуйкова, д. 3', 0);
INSERT INTO Person(Person_ID,Last_Name,First_Name,Date_birth,Phone,Address,Regular) VALUES (3, 'Антонов', 'Парис', '1998-05-31', '+79179474444', 'ул. Лебедева, д. 2', 0);
INSERT INTO Person(Person_ID,Last_Name,First_Name,Date_birth,Phone,Address,Regular) VALUES (4, 'Бог', 'Кассандра', '1999-01-05', '+79172174444', 'ул. Главная, д. 15', 1);
INSERT INTO Person(Person_ID,Last_Name,First_Name,Date_birth,Phone,Address,Regular) VALUES (5, 'Всежкин', 'Пельмежкин', '1999-06-01', '+79979174444', 'ул. Шишкмина, д. 32', 0);
INSERT INTO Person(Person_ID,Last_Name,First_Name,Date_birth,Phone,Address,Regular) VALUES (6, 'Пушкин', 'Александр', '1799-06-06', '+79229174444', 'Набережная реки Мойки, д. 12', 1);
INSERT INTO Person(Person_ID,Last_Name,First_Name,Date_birth,Phone,Address,Regular) VALUES (7, 'Дандонов', 'Юрий', '1990-02-01', '+79189332244', 'ул. Пушкина, д. 8', 1);
INSERT INTO Person(Person_ID,Last_Name,First_Name,Date_birth,Phone,Address,Regular) VALUES (8, 'Парамонов', 'Атамон', '1988-03-31', '+791439171444', 'ул. Пушкина, д. 756', 1);
INSERT INTO Person(Person_ID,Last_Name,First_Name,Date_birth,Phone,Address,Regular) VALUES (9, 'Кузькин', 'Денис', '1993-02-02', '+79179321244', 'ул. Пушкина, д. 4123', 0);
INSERT INTO Person(Person_ID,Last_Name,First_Name,Date_birth,Phone,Address,Regular) VALUES (10, 'Велкин', 'Александр', '1898-11-21', '+71239174444', 'ул. Пушкина, д. 123', 0);
INSERT INTO Person(Person_ID,Last_Name,First_Name,Date_birth,Phone,Address,Regular) VALUES (11, 'Бродов', 'Вениамин', '1965-11-15', '+79567173444', 'ул. Пушкина, д. 21а', 1);
INSERT INTO Person(Person_ID,Last_Name,First_Name,Date_birth,Phone,Address,Regular) VALUES (12, 'Вологин', 'Илья', '2000-04-09', '+79179324454', 'ул. Пушкина, д. 253а', 0);
INSERT INTO Person(Person_ID,Last_Name,First_Name,Date_birth,Phone,Address,Regular) VALUES (13, 'Кашинка', 'Машинка', '1962-11-28', '+79234176444', 'ул. Пушкина, д. 6', 0);
INSERT INTO Person(Person_ID,Last_Name,First_Name,Date_birth,Phone,Address,Regular) VALUES (14, 'Пелемонов', 'Вячеслав', '1972-10-12', '+79789177444', 'ул. Пушкина, д. 568', 0);
INSERT INTO Person(Person_ID,Last_Name,First_Name,Date_birth,Phone,Address,Regular) VALUES (15, 'Оргиенко', 'София', '1998-11-01', '+79179323448', 'ул. Пушкина, д. 56', 1);
INSERT INTO Person(Person_ID,Last_Name,First_Name,Date_birth,Phone,Address,Regular) VALUES (16, 'Олежкин', 'Олег', '1998-12-21', '+791745673449', 'ул. Волкова, д. 6', 1);
INSERT INTO Person(Person_ID,Last_Name,First_Name,Date_birth,Phone,Address,Regular) VALUES (17, 'Васильев', 'Валерий', '1968-01-23', '+79567323494', 'ул. Степная, д. 33', 1);
INSERT INTO Person(Person_ID,Last_Name,First_Name,Date_birth,Phone,Address,Regular) VALUES (18, 'Куриенко', 'Наталья', '1998-11-01', '+79179323474', 'ул. Ленина, д. 521', 1);
INSERT INTO Person(Person_ID,Last_Name,First_Name,Date_birth,Phone,Address,Regular) VALUES (19, 'Вальсичиков', 'Георгий', '1998-11-01', '+79179328444', 'Ленинский проспект, д. 234', 1);
INSERT INTO Person(Person_ID,Last_Name,First_Name,Date_birth,Phone,Address,Regular) VALUES (20, 'Орленина', 'Анастасия', '1998-11-01', '+79179323444', 'ул. Гражданская, д. 22', 1);
INSERT INTO Person(Person_ID,Last_Name,First_Name,Date_birth,Phone,Address,Regular) VALUES (21, 'Парженин', 'Вавел', '1998-11-01', '+79179323441', 'Комендантский проспект, д. 5', 1);
INSERT INTO Person(Person_ID,Last_Name,First_Name,Date_birth,Phone,Address,Regular) VALUES (22, 'Олененко', 'Андрей', '1998-11-01', '+79179323442', 'ул. Ваенги, д. 64', 1);
INSERT INTO Person(Person_ID,Last_Name,First_Name,Date_birth,Phone,Address,Regular) VALUES (23, 'Ерешников', 'Евгениц', '1998-11-01', '+79179323443', 'ул. Екатерининская, д. 75', 1);
INSERT INTO Person(Person_ID,Last_Name,First_Name,Date_birth,Phone,Address,Regular) VALUES (24, 'Пульнимаева', 'Мария', '1998-11-01', '+79179323445', 'ул. Нормированная, д. 32', 1);
INSERT INTO Person(Person_ID,Last_Name,First_Name,Date_birth,Phone,Address,Regular) VALUES (25, 'Пименов', 'Даниил', '1998-11-01', '+79669323444', 'ул. Партизанская, д. 234', 1);

INSERT INTO Type_of_payment(Type_of_payment_ID,Type_of_pay) VALUES (1, 'Наличными');
INSERT INTO Type_of_payment(Type_of_payment_ID,Type_of_pay) VALUES (2, 'Карта');
INSERT INTO Type_of_payment(Type_of_payment_ID,Type_of_pay) VALUES (3, 'Перевод');
INSERT INTO Type_of_payment(Type_of_payment_ID,Type_of_pay) VALUES (4, 'Кредит');
INSERT INTO Type_of_payment(Type_of_payment_ID,Type_of_pay) VALUES (5, 'Рассрочка');
	
INSERT INTO Type_of_Tour(Tour_type_ID, Tour_type) VALUES (1, 'Пляжный');
INSERT INTO Type_of_Tour(Tour_type_ID, Tour_type) VALUES (2, 'Экскурсионный');
INSERT INTO Type_of_Tour(Tour_type_ID, Tour_type) VALUES (3, 'Спортивный');
INSERT INTO Type_of_Tour(Tour_type_ID, Tour_type) VALUES (4, 'Походный');
INSERT INTO Type_of_Tour(Tour_type_ID, Tour_type) VALUES (5, 'Морской');
INSERT INTO Type_of_Tour(Tour_type_ID, Tour_type) VALUES (6, 'Прогулочный');
	
INSERT INTO Base_of_Countries(Country_ID,Country) VALUES (1, 'Россия');
INSERT INTO Base_of_Countries(Country_ID,Country) VALUES (2, 'США');
INSERT INTO Base_of_Countries(Country_ID,Country) VALUES (3, 'Норвегия');
INSERT INTO Base_of_Countries(Country_ID,Country) VALUES (4, 'Англия');
INSERT INTO Base_of_Countries(Country_ID,Country) VALUES (5, 'Ирландия');
INSERT INTO Base_of_Countries(Country_ID,Country) VALUES (6, 'Финляндия');
INSERT INTO Base_of_Countries(Country_ID,Country) VALUES (7,'Эстония');
INSERT INTO Base_of_Countries(Country_ID,Country) VALUES (8, 'Франция');
INSERT INTO Base_of_Countries(Country_ID,Country) VALUES (9, 'Германия');
INSERT INTO Base_of_Countries(Country_ID,Country) VALUES (10, 'Австралия');
INSERT INTO Base_of_Countries(Country_ID,Country) VALUES (11, 'Китай');
INSERT INTO Base_of_Countries(Country_ID,Country) VALUES (12, 'Япония');
INSERT INTO Base_of_Countries(Country_ID,Country) VALUES (13, 'Индия');

INSERT INTO Base_of_Localities(Locality_ID,Locality,Country_ID) VALUES (1, 'Санкт-Петербург', 1);
INSERT INTO Base_of_Localities(Locality_ID,Locality,Country_ID) VALUES (2, 'Москва', 1);
INSERT INTO Base_of_Localities(Locality_ID,Locality,Country_ID) VALUES (3, 'Казань', 1);
INSERT INTO Base_of_Localities(Locality_ID,Locality,Country_ID) VALUES (4, 'Бостон', 2);
INSERT INTO Base_of_Localities(Locality_ID,Locality,Country_ID) VALUES (5, 'Нью-Йорк', 2);
INSERT INTO Base_of_Localities(Locality_ID,Locality,Country_ID) VALUES (6, 'Сан-Франциско', 2);
INSERT INTO Base_of_Localities(Locality_ID,Locality,Country_ID) VALUES (7, 'Осло', 3);
INSERT INTO Base_of_Localities(Locality_ID,Locality,Country_ID) VALUES (8, 'Лондон', 4);
INSERT INTO Base_of_Localities(Locality_ID,Locality,Country_ID) VALUES (9, 'Дублин', 5);
INSERT INTO Base_of_Localities(Locality_ID,Locality,Country_ID) VALUES (10, 'Хельсинки', 6);
INSERT INTO Base_of_Localities(Locality_ID,Locality,Country_ID) VALUES (11, 'Таллин', 7);
INSERT INTO Base_of_Localities(Locality_ID,Locality,Country_ID) VALUES (12, 'Париж', 8);
INSERT INTO Base_of_Localities(Locality_ID,Locality,Country_ID) VALUES (13, 'Берлин', 9);
INSERT INTO Base_of_Localities(Locality_ID,Locality,Country_ID) VALUES (14, 'Сидней', 10);
INSERT INTO Base_of_Localities(Locality_ID,Locality,Country_ID) VALUES (15, 'Шанхай', 11);
INSERT INTO Base_of_Localities(Locality_ID,Locality,Country_ID) VALUES (16, 'Токио', 12);
INSERT INTO Base_of_Localities(Locality_ID,Locality,Country_ID) VALUES (17, 'Дели', 13);
INSERT INTO Base_of_Localities(Locality_ID,Locality,Country_ID) VALUES (18, 'Лос Анджелес', 2);
INSERT INTO Base_of_Localities(Locality_ID,Locality,Country_ID) VALUES (19, 'Пенза', 1);
INSERT INTO Base_of_Localities(Locality_ID,Locality,Country_ID) VALUES (20, 'Ницца', 8);


INSERT INTO Hotel(Hotel_ID,Hotel_name,Hotel_type,Locality_ID,Phone,Address) VALUES (1, 'Bomba', 4, 1, '+79192823912', 'ул. Гороховая д.32');
INSERT INTO Hotel(Hotel_ID,Hotel_name,Hotel_type,Locality_ID,Phone,Address) VALUES (2, 'Moscow5', 5, 2, '+79832223334', 'ул. Ленина д.1');
INSERT INTO Hotel(Hotel_ID,Hotel_name,Hotel_type,Locality_ID,Phone,Address) VALUES (3, 'Kazantip', 3, 3, '+79179223321', 'ул. Глушко д.5');
INSERT INTO Hotel(Hotel_ID,Hotel_name,Hotel_type,Locality_ID,Phone,Address) VALUES (4, 'BO$$', 5, 4, '+19876543210', 'Great Park st.212');
INSERT INTO Hotel(Hotel_ID,Hotel_name,Hotel_type,Locality_ID,Phone,Address) VALUES (5, 'ILNY', 2, 5, '+14345673412', 'HomeGit st.133');
INSERT INTO Hotel(Hotel_ID,Hotel_name,Hotel_type,Locality_ID,Phone,Address) VALUES (6, 'SanSanych', 1, 6, '+18987656574', 'JetGet st.65');
INSERT INTO Hotel(Hotel_ID,Hotel_name,Hotel_type,Locality_ID,Phone,Address) VALUES (7, 'Capital', 5, 8, '+230942309423', 'Victory st.234');
INSERT INTO Hotel(Hotel_ID,Hotel_name,Hotel_type,Locality_ID,Phone,Address) VALUES (8, 'DoubleLin', 3, 9, '+42352135134', 'Beer st.2');
INSERT INTO Hotel(Hotel_ID,Hotel_name,Hotel_type,Locality_ID,Phone,Address) VALUES (9, 'Hennhessy', 3, 10, '+897656456567', 'PPulpulski st.85');
INSERT INTO Hotel(Hotel_ID,Hotel_name,Hotel_type,Locality_ID,Phone,Address) VALUES (10, 'sTALLIN', 4, 11, '+828376252323', 'Prezhev st.4');
INSERT INTO Hotel(Hotel_ID,Hotel_name,Hotel_type,Locality_ID,Phone,Address) VALUES (11, 'PerryFR', 4, 12, '+28357981234', 'LeDivah st.234');
INSERT INTO Hotel(Hotel_ID,Hotel_name,Hotel_type,Locality_ID,Phone,Address) VALUES (12, 'BershkaHotel', 5, 13, '+92378511987', 'Hasdkasdkjas st.123');
INSERT INTO Hotel(Hotel_ID,Hotel_name,Hotel_type,Locality_ID,Phone,Address) VALUES (13, 'SidAndNency', 2, 14, '+1273262352387', 'Hopefull st.86');
INSERT INTO Hotel(Hotel_ID,Hotel_name,Hotel_type,Locality_ID,Phone,Address) VALUES (14, 'Penza Grant Hotel', 1, 19, '+71232359845', 'ул. Мира, д.3');
INSERT INTO Hotel(Hotel_ID,Hotel_name,Hotel_type,Locality_ID,Phone,Address) VALUES (15, 'Los Sos', 5, 18, '+1123153252625', 'Perfect st.4');
INSERT INTO Hotel(Hotel_ID,Hotel_name,Hotel_type,Locality_ID,Phone,Address) VALUES (16, 'Tatarstan', 5, 3, '+79179453332', 'Площадь Габдулы Тукая д.1');
	
INSERT INTO Tour(Tour_ID,Tour_type_ID,Hotel_ID,Date_Tour_Start,Date_Tour_End) VALUES (1, 1, 1, '2020-06-01','2020-06-14');
INSERT INTO Tour(Tour_ID,Tour_type_ID,Hotel_ID,Date_Tour_Start,Date_Tour_End) VALUES (2, 3, 14, '2020-07-01','2020-07-09');
INSERT INTO Tour(Tour_ID,Tour_type_ID,Hotel_ID,Date_Tour_Start,Date_Tour_End) VALUES (3, 4, 15, '2020-07-03','2020-07-28');
INSERT INTO Tour(Tour_ID,Tour_type_ID,Hotel_ID,Date_Tour_Start,Date_Tour_End) VALUES (4, 3, 2, '2020-03-03','2020-03-15');
INSERT INTO Tour(Tour_ID,Tour_type_ID,Hotel_ID,Date_Tour_Start,Date_Tour_End) VALUES (5, 2, 3, '2020-07-26','2020-08-08');
INSERT INTO Tour(Tour_ID,Tour_type_ID,Hotel_ID,Date_Tour_Start,Date_Tour_End) VALUES (6, 5, 4, '2020-08-13','2020-09-02');
INSERT INTO Tour(Tour_ID,Tour_type_ID,Hotel_ID,Date_Tour_Start,Date_Tour_End) VALUES (7, 6, 13, '2020-08-14','2020-08-18');
INSERT INTO Tour(Tour_ID,Tour_type_ID,Hotel_ID,Date_Tour_Start,Date_Tour_End) VALUES (8, 6, 12, '2020-10-20','2020-10-28');
INSERT INTO Tour(Tour_ID,Tour_type_ID,Hotel_ID,Date_Tour_Start,Date_Tour_End) VALUES (9, 5, 11, '2020-11-23','2020-12-05');
INSERT INTO Tour(Tour_ID,Tour_type_ID,Hotel_ID,Date_Tour_Start,Date_Tour_End) VALUES (10, 6, 10, '2020-10-14','2020-11-01');
INSERT INTO Tour(Tour_ID,Tour_type_ID,Hotel_ID,Date_Tour_Start,Date_Tour_End) VALUES (11, 4, 9, '2021-01-03','2021-01-15');
INSERT INTO Tour(Tour_ID,Tour_type_ID,Hotel_ID,Date_Tour_Start,Date_Tour_End) VALUES (12, 3, 8, '2022-04-05','2022-04-18');
INSERT INTO Tour(Tour_ID,Tour_type_ID,Hotel_ID,Date_Tour_Start,Date_Tour_End) VALUES (13, 2, 7, '2020-12-25','2021-01-08');
INSERT INTO Tour(Tour_ID,Tour_type_ID,Hotel_ID,Date_Tour_Start,Date_Tour_End) VALUES (14, 2, 5, '2021-07-01','2021-07-09');
INSERT INTO Tour(Tour_ID,Tour_type_ID,Hotel_ID,Date_Tour_Start,Date_Tour_End) VALUES (15, 1, 6, '2021-08-13','2021-09-02');
INSERT INTO Tour(Tour_ID,Tour_type_ID,Hotel_ID,Date_Tour_Start,Date_Tour_End) VALUES (16, 1, 5, '2021-03-02','2021-03-20');
INSERT INTO Tour(Tour_ID,Tour_type_ID,Hotel_ID,Date_Tour_Start,Date_Tour_End) VALUES (17, 3, 4, '2022-04-10','2022-04-28');
INSERT INTO Tour(Tour_ID,Tour_type_ID,Hotel_ID,Date_Tour_Start,Date_Tour_End) VALUES (18, 3, 3, '2021-04-10','2021-04-28');
INSERT INTO Tour(Tour_ID,Tour_type_ID,Hotel_ID,Date_Tour_Start,Date_Tour_End) VALUES (19, 4, 2, '2021-03-28','2021-04-25');
INSERT INTO Tour(Tour_ID,Tour_type_ID,Hotel_ID,Date_Tour_Start,Date_Tour_End) VALUES (20, 4, 1, '2020-11-28','2020-12-13');
INSERT INTO Tour(Tour_ID,Tour_type_ID,Hotel_ID,Date_Tour_Start,Date_Tour_End) VALUES (21, 1, 7, '2021-03-12','2021-04-01');
INSERT INTO Tour(Tour_ID,Tour_type_ID,Hotel_ID,Date_Tour_Start,Date_Tour_End) VALUES (22, 1, 15, '2021-06-14','2021-06-30');
INSERT INTO Tour(Tour_ID,Tour_type_ID,Hotel_ID,Date_Tour_Start,Date_Tour_End) VALUES (23, 5, 10, '2021-07-09','2021-07-29');
INSERT INTO Tour(Tour_ID,Tour_type_ID,Hotel_ID,Date_Tour_Start,Date_Tour_End) VALUES (24, 5, 9, '2020-07-05','2020-07-25');
INSERT INTO Tour(Tour_ID,Tour_type_ID,Hotel_ID,Date_Tour_Start,Date_Tour_End) VALUES (25, 4, 2, '2020-04-15','2020-05-01');
	
INSERT INTO OrderT(Order_ID,Person_ID,Tour_ID,Price,Type_of_payment_ID,Time_Order,Is_Done,Comments) VALUES (1,1,1,100000,1,'2020-01-04', 1, 'Побольше жарково');
INSERT INTO OrderT(Order_ID,Person_ID,Tour_ID,Price,Type_of_payment_ID,Time_Order,Is_Done,Comments) VALUES (2,2,2,150000,2,'2020-01-04', 1, 'Не хочу шумных соседей');
INSERT INTO OrderT(Order_ID,Person_ID,Tour_ID,Price,Type_of_payment_ID,Time_Order,Is_Done,Comments) VALUES (3,3,3,100000,3,'2020-01-04', 1, NULL);
INSERT INTO OrderT(Order_ID,Person_ID,Tour_ID,Price,Type_of_payment_ID,Time_Order,Is_Done,Comments) VALUES (4,4,4,20000,4,'2020-01-05', 1, NULL);
INSERT INTO OrderT(Order_ID,Person_ID,Tour_ID,Price,Type_of_payment_ID,Time_Order,Is_Done,Comments) VALUES (5,5,25,40000,5,'2020-01-05', 1, NULL);
INSERT INTO OrderT(Order_ID,Person_ID,Tour_ID,Price,Type_of_payment_ID,Time_Order,Is_Done,Comments) VALUES (6,6,24,60000,3,'2020-01-05', 1, NULL);
INSERT INTO OrderT(Order_ID,Person_ID,Tour_ID,Price,Type_of_payment_ID,Time_Order,Is_Done,Comments) VALUES (7,7,23,60000,3,'2020-01-05', 1, 'Хочу побольше еды');
INSERT INTO OrderT(Order_ID,Person_ID,Tour_ID,Price,Type_of_payment_ID,Time_Order,Is_Done,Comments) VALUES (8,8,22,70000,2,'2020-01-06', 1, NULL);
INSERT INTO OrderT(Order_ID,Person_ID,Tour_ID,Price,Type_of_payment_ID,Time_Order,Is_Done,Comments) VALUES (9,9,21,85000,5,'2020-01-06', 1, NULL);
INSERT INTO OrderT(Order_ID,Person_ID,Tour_ID,Price,Type_of_payment_ID,Time_Order,Is_Done,Comments) VALUES (10,10,20,350000,4,'2020-01-06', 0, NULL);
INSERT INTO OrderT(Order_ID,Person_ID,Tour_ID,Price,Type_of_payment_ID,Time_Order,Is_Done,Comments) VALUES (11,11,19,40000,4,'2020-01-06', 0, 'Могу уехать пораньше');
INSERT INTO OrderT(Order_ID,Person_ID,Tour_ID,Price,Type_of_payment_ID,Time_Order,Is_Done,Comments) VALUES (12,12,18,30000,2,'2020-01-06', 0, NULL);
INSERT INTO OrderT(Order_ID,Person_ID,Tour_ID,Price,Type_of_payment_ID,Time_Order,Is_Done,Comments) VALUES (13,13,17,40000,2,'2020-01-06', 0, NULL);
INSERT INTO OrderT(Order_ID,Person_ID,Tour_ID,Price,Type_of_payment_ID,Time_Order,Is_Done,Comments) VALUES (14,14,16,50000,2,'2020-01-07', 0, NULL);
INSERT INTO OrderT(Order_ID,Person_ID,Tour_ID,Price,Type_of_payment_ID,Time_Order,Is_Done,Comments) VALUES (15,15,15,55000,2,'2020-01-07', 0, 'Не сразу заплачу...');
INSERT INTO OrderT(Order_ID,Person_ID,Tour_ID,Price,Type_of_payment_ID,Time_Order,Is_Done,Comments) VALUES (16,16,14,55500,3,'2020-01-07', 0, NULL);
INSERT INTO OrderT(Order_ID,Person_ID,Tour_ID,Price,Type_of_payment_ID,Time_Order,Is_Done,Comments) VALUES (17,17,13,84000,4,'2020-01-07', 0, NULL);
INSERT INTO OrderT(Order_ID,Person_ID,Tour_ID,Price,Type_of_payment_ID,Time_Order,Is_Done,Comments) VALUES (18,18,12,97000,1,'2020-01-07', 0, NULL);
INSERT INTO OrderT(Order_ID,Person_ID,Tour_ID,Price,Type_of_payment_ID,Time_Order,Is_Done,Comments) VALUES (19,19,11,37000,1,'2020-01-07', 0, 'Приедет подруга');
INSERT INTO OrderT(Order_ID,Person_ID,Tour_ID,Price,Type_of_payment_ID,Time_Order,Is_Done,Comments) VALUES (20,20,10,64000,2,'2020-01-07', 0, NULL);
INSERT INTO OrderT(Order_ID,Person_ID,Tour_ID,Price,Type_of_payment_ID,Time_Order,Is_Done,Comments) VALUES (21,21,9,85000,3,'2020-01-08', 0, NULL);
INSERT INTO OrderT(Order_ID,Person_ID,Tour_ID,Price,Type_of_payment_ID,Time_Order,Is_Done,Comments) VALUES (22,22,8,75000,3,'2020-01-08', 0, NULL);
INSERT INTO OrderT(Order_ID,Person_ID,Tour_ID,Price,Type_of_payment_ID,Time_Order,Is_Done,Comments) VALUES (23,23,7,51000,3,'2020-01-08', 0, 'Мне 31');
INSERT INTO OrderT(Order_ID,Person_ID,Tour_ID,Price,Type_of_payment_ID,Time_Order,Is_Done,Comments) VALUES (24,24,6,26000,2,'2020-01-08', 0, NULL);
INSERT INTO OrderT(Order_ID,Person_ID,Tour_ID,Price,Type_of_payment_ID,Time_Order,Is_Done,Comments) VALUES (25,25,5,123000,2,'2020-01-08', 0, NULL);



/*---------------------------------------------
 				SERVER CLIENT
 --------------------------------------------*/


/*----------------FUNCTIONS------------------*/

/*		Choose Hotel by type		*/
DELIMITER //
CREATE PROCEDURE ChooseHotel(IN var_Locality VARCHAR(50))
BEGIN
	SELECT Hotel.* FROM Hotel, Base_of_Localities WHERE Base_of_Localities.Locality_ID = Hotel.Locality_ID AND Base_of_Localities.Locality = var_Locality ORDER BY Hotel.Hotel_type; 
END;
//
DELIMITER ;
/*DROP PROCEDURE ChooseHotel;*/
/*CALL ChooseHotel('Казань');*/

/*		Add new Locality		*/
DELIMITER //
CREATE PROCEDURE AddLocal(IN var_Local VARCHAR(50), IN var_Country VARCHAR(20))
BEGIN
	DECLARE x INTEGER;
	SELECT x = MAX(Country_ID) FROM Base_of_Countries;
	IF var_Country NOT IN (SELECT Country from Base_of_Countries) THEN
		INSERT INTO Base_of_Countries(Country_ID,Country) VALUES (x + 1, var_Country);
	END IF;
	IF var_Local NOT IN (SELECT Locality from Base_of_Localities) THEN
		INSERT INTO Base_of_Localities(Locality_ID,Locality,Country_ID) VALUES (MAX(Base_of_Localities.Locality_ID) + 1, var_Local, x + 1);
	END IF;
END;
//
DELIMITER ;
/*DROP PROCEDURE AddLocal;*/

/*		Add new Hotel		*/
DELIMITER //
CREATE PROCEDURE AddHotel(var_HotelName VARCHAR(30),var_Hoteltype INTEGER,  var_Phone VARCHAR(15),
				var_Address VARCHAR(50), IN var_Local VARCHAR(50), IN var_Country VARCHAR(20))
BEGIN
	CALL AddLocal(var_Local, var_Country);
	SELECT y = MAX(Hotel_ID) FROM Hotel;
	SELECT z = Locality_ID FROM Base_of_Localities WHERE Locality = var_Local;
	INSERT INTO Hotel(Hotel_ID,Hotel_name,Hotel_type,Locality_ID,Phone,Address) VALUES (y, var_HotelName, var_Hoteltype, z, var_Phone, var_Address);
END;
//
DELIMITER ;
/*DROP PROCEDURE AddHotel;*/



/*------------------VIEWS--------------------*/

/*		Orders that are not done	*/
CREATE VIEW Not_Done_Orders
	AS SELECT * FROM OrderT WHERE Is_Done=0;
/*DROP VIEW Not_Done_Orders;*/

/*		Full info from orders		*/
CREATE VIEW Full_Order_Info
	AS SELECT OrderT.Order_ID, OrderT.Is_Done, Person.Last_Name, Person.First_Name, Person.Phone, 
	Person.Regular, Type_of_Tour.Tour_type, Base_of_Countries.Country, 
	Base_of_Localities.Locality, Hotel.Hotel_Name, Hotel.Address, OrderT.Price, Type_of_payment.Type_of_pay
	FROM Person, Type_of_payment, Base_of_Countries, Base_of_Localities, Type_of_Tour, Hotel, Tour, OrderT 
	WHERE OrderT.Person_ID = Person.Person_ID 
		AND Type_of_payment.Type_of_payment_ID = OrderT.Type_of_payment_ID
		AND Type_of_Tour.Tour_type_ID = Tour.Tour_type_ID
		AND Base_of_Localities.Country_ID = Base_of_Countries.Country_ID
		AND Base_of_Localities.Locality_ID = Hotel.Locality_ID
		AND (Tour.Hotel_ID = Hotel.Hotel_ID)
		AND Tour.Tour_ID = OrderT.Tour_ID;
/*DROP VIEW Full_Order_Info;*/

/*		Info about credit people or people with payment by instalments		*/
CREATE VIEW Credit_Person
	AS SELECT Person.*, Type_of_payment.Type_of_pay FROM Person, Type_of_payment, OrderT 
		WHERE OrderT.Person_ID = Person.Person_ID 
			AND Type_of_payment.Type_of_payment_ID = OrderT.Type_of_payment_ID
			AND Type_of_payment.Type_of_payment_ID IN (4, 5);
/*DROP VIEW Credit_Person;*/		
			
		
		
/*-----------------Triggers-------------------*/		

/*		Ban on deletion Persons		*/		
DELIMITER //
CREATE TRIGGER TR_del_Person 
	AFTER DELETE ON Person FOR EACH ROW
		BEGIN 
			SIGNAL sqlstate '45001' set message_text = "No way ! You cannot do this !";
		END;
//
DELIMITER ;
/*DROP TRIGGER TR_del_Person;*/
/*DELETE FROM Person WHERE Person_ID = 4;*/
		
/*		Ban on deletion Orders		*/
DELIMITER //
CREATE TRIGGER TR_del_Order 
	AFTER INSERT ON OrderT FOR EACH ROW
		BEGIN
			SIGNAL sqlstate '45001' set message_text = "No way ! You cannot do this !";
		END;
//
DELIMITER ;
/*DROP TRIGGER TR_del_Order;*/
/*DELETE FROM OrderT WHERE Order_ID = 4;*/

/*		Ban on inserting orders which are already done		*/
DELIMITER //
CREATE TRIGGER TR_ins_DoneOrders 
	AFTER INSERT ON OrderT FOR EACH ROW
		BEGIN
			IF NEW.Is_Done = 1 THEN 
				SIGNAL sqlstate '45001' set message_text = "No way ! You cannot do this !";
			END IF;
		END;
//
DELIMITER ;
/*DROP TRIGGER TR_ins_DoneOrders;*/		
		
/*-----------------Indexes-------------------*/

CREATE INDEX idx_full_Name ON Person(First_Name, Last_Name, Phone);
CREATE INDEX idx_hotel_info ON Hotel(Hotel_name, Hotel_type);
CREATE INDEX idx_countries ON Base_of_Countries(Country);

/*DROP INDEX idx_full_Name ON Person;
  DROP INDEX idx_hotel_info ON Hotel;
  DROP INDEX idx_countries ON Base_of_Countries;
 */
		
/*---------------------------------------------
 				CLIENT PART
 --------------------------------------------*/
		
UPDATE Tour SET Date_Tour_Start = '2021-07-06' WHERE Tour_ID = 3;

UPDATE Tour SET Date_Tour_END = '2021-07-25' WHERE Tour_ID = 3;

SELECT * FROM Hotel WHERE Hotel_type = 4 ORDER BY Hotel_name;

SELECT Country FROM Base_of_Countries ORDER BY Country;

SELECT Locality FROM Base_of_Localities L, Base_of_Countries C
	WHERE L.Country_ID = C.Country_ID AND C.Country = 'США' ORDER BY Locality;

SELECT Tour_type FROM Type_of_Tour;

SELECT * FROM OrderT ot WHERE Is_Done = 0 ORDER BY Time_Order;

SELECT Address FROM Hotel WHERE Hotel_name = 'Tatarstan';

SELECT p.First_Name, p.Last_Name, p.Phone, ot.Price, top.Type_of_pay, t.Date_Tour_Start, t.Date_Tour_End, tot.Tour_type, h.Hotel_name
	FROM Person p, OrderT ot, Tour t, Type_of_payment top, Type_of_Tour tot, Hotel h 
		WHERE p.Person_ID = ot.Person_ID 
			AND ot.Type_of_payment_ID = top.Type_of_payment_ID
			AND ot.Tour_ID = t.Tour_ID 
			AND t.Tour_type_ID = tot.Tour_type_ID
			AND ot.Is_Done = 0
			AND t.Hotel_ID = h.Hotel_ID ORDER BY t.Date_Tur_Start;
		
SELECT * FROM Person p WHERE Regular = 1 ORDER BY Last_Name;

SELECT p.Last_Name, p.First_Name, ot.Price, ot.Time_Order FROM Person p LEFT OUTER JOIN OrderT ot ON p.Person_ID = ot.Person_ID;

SELECT tot.Tour_type, AVG(ot.Price)
	FROM OrderT ot, Tour t, Type_of_Tour tot
		WHERE ot.Tour_ID = t.Tour_ID 
			AND t.Tour_type_ID = tot.Tour_type_ID
				GROUP BY tot.Tour_type HAVING AVG(ot.Price) < 80000;

SELECT First_Name, Last_Name, Phone FROM Person WHERE Person_ID = ANY (
	SELECT Person_ID FROM OrderT WHERE Price < 70000);

SELECT h.Hotel_name, h.Hotel_type, l.Locality FROM Hotel h, (SELECT Locality_ID, Locality FROM Base_of_Localities bl
			WHERE Country_ID = (SELECT Country_ID FROM Base_of_Countries WHERE Country = 'Россия')) l
				WHERE l.Locality_ID = h.Locality_ID ORDER BY h.Hotel_type;

(SELECT Locality, 'Есть связь с отелями' FROM Base_of_Localities 
	WHERE Locality_ID IN (SELECT Locality_ID FROM Hotel))
UNION
(SELECT Locality, 'Отсутствует' FROM Base_of_Localities
	WHERE Locality_ID NOT IN (SELECT Locality_ID FROM Hotel));


/*DROP TABLE OrderT;
  DROP TABLE Tour;
  DROP TABLE Hotel;
  DROP TABLE Base_of_Localities;
  DROP TABLE Base_of_Countries;
  DROP TABLE Type_of_Tour;
  DROP TABLE Type_of_payment;
  DROP TABLE Person;
 */



