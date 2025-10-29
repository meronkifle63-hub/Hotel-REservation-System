M✨, [6/1/2025 9:04 PM]
package hotelresevationsystem;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Bookings {
    private Guest guest;
    private Room room;
    private int numberOfNights;
    private String checkInDate;

    public Bookings(Guest guest, Room room, String checkInDate) {
        this.guest = guest;
        this.room = room;
        this.checkInDate= checkInDate;
        bookingsList.add(this);
    }
    
   public int getRoomNumber() {
        return room.getRoomNumber();
    }

    public Guest getGuest() {
        return guest;
    }
   
    public void setRoom(Room room) {
    this.room = room;
}

    public void setCheckInDate(String date) {
    this.checkInDate = date;
}

    public static void addBooking(Bookings booking) {
    bookingsList.add(booking);
}
    
    private static List<Bookings> bookingsList = new ArrayList<>();

    public static void cancelBookingByName(String name) {
        Bookings booking = findBookingByName(name);
        if (booking != null) {
            bookingsList.remove(booking);
            System.out.println("Booking canceled successfully for " + name);
        } else {
            System.out.println("No booking found for " + name);
        }
    }

    public static void viewBookingByName(String name) {
        Bookings booking = findBookingByName(name);
        if (booking != null) {
            booking.showBookingDetails();
        } else {
            System.out.println("No booking found for " + name);
        }
    }

    public static void updateBookingByName(String name, Scanner scanner) {
        Bookings booking = findBookingByName(name);
        if (booking != null) {
            System.out.println("Enter new check-in date (yyyy-mm-dd): ");
            String newDate = scanner.nextLine();
            booking.setCheckInDate(newDate);  // if you have such method
            System.out.println("Booking updated successfully.");
        } else {
            System.out.println("No booking found for " + name);
        }
    }

    public static void deleteBookingByName(String name) {
        cancelBookingByName(name); // reuse
    }

    public static Bookings findBookingByName(String name) {
        for (Bookings b : bookingsList) {
            if (b.getGuest().getName().equalsIgnoreCase(name)) {
                return b;
            } else {
            }
        }
        return null;
    }
   
   public void showBookingDetails(){
        double totalPrice = room.Calculate_Total_Price();
        guest.displayGuest();
        System.out.println("Room Type: "+ room.getRoomtype());
        System.out.println("Room Number: " + room.getRoomNumber());
        System.out.println("Number of Nights: "+ room.getNumber_of_Nights());
        System.out.println("Total Price: "+ totalPrice + " ETB.");
        System.out.println("Check-In Date: " + (checkInDate != null ? checkInDate : "Not Set"));
        
        LocalDate checkIn = LocalDate.parse(checkInDate);
        LocalDate checkOut = checkIn.plusDays(room.getNumber_of_Nights());
        System.out.println("Check-Out Date: " + checkOut);
  
   }
   
    public static List<Bookings> getAllBookings() {
    return bookingsList;
    }

}

M✨, [6/1/2025 9:04 PM]
package hotelresevationsystem;

import java.util.ArrayList;
import java.util.List;

public class RoomManager {
    private static int NextRoomNumber= 100; // start room numbers from 100
    private static List<Room> rooms = new ArrayList<>();
    
    public static int getNextRoomNumber() {
        return NextRoomNumber++;
    }

    public static void addRoom(Room room) {
        rooms.add(room);
    }

   
    public static List<Room> getRooms() {
        return rooms;
    }
   
}

M✨, [6/1/2025 9:04 PM]
package hotelresevationsystem;

public class DoubleRoom extends Room {
    
     private static final double PricePerNight= 3000.00;

    public DoubleRoom(int RoomNumber, boolean isAvailable) {
        super(RoomNumber, isAvailable);
    }
    
    @Override
     public double CalculatePricePerNight(){
         return PricePerNight;
     }
    @Override
    public String getRoomtype(){
        return "Double Room!!";
    }
    
}

M✨, [6/1/2025 9:04 PM]
package hotelresevationsystem;

import java.util.Scanner;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;

public class HotelReservationSystem {
    private Room room;

     public static void AdminMenu(Scanner scanner){
        boolean exit= false;
        
        while(!exit){
            System.out.println("--------------------------------------------");
            System.out.println("                Admin Menu                  ");
            System.out.println("--------------------------------------------");
            System.out.println("1- Add New Rooms");
            System.out.println("2- View All Booking");
            System.out.println("3- Update Booking");
            System.out.println("4- Delete Booking");
            System.out.println("5- Back to Main Menu");
            
            System.out.println("--------------------------------------------");
            System.out.print("Enter Your Choice: ");
           
            int choice= scanner.nextInt();
          
            
           switch(choice){
                case 1:
                    AddNewRooms(scanner);
                    break;
                case 2: 
                    ViewAllBookings();
                    break;
                case 3:
                    UpdateBookingAdmin(scanner);
                    break;
                case 4: 
                    DeleteBookingAdmin(scanner);
                    break;
                case 5:
                    exit= true;
                    break; 
                default:
                    System.out.println("Invalid Choice!!!");
            }
        }
        
    }
    
    public static void CustomerMenu(Scanner scanner){
        boolean exit = false;
        
        
        while(!exit){
            
            System.out.println("--------------------------------------------");
            System.out.println("            Customer Menu                   ");
            System.out.println("--------------------------------------------");
            System.out.println("1- Book a Room");
            System.out.println("2- Cancel Booking");
            System.out.println("3- View Booking");
            System.out.println("4- Back to Main Menu");
            
            
            System.out.println("--------------------------------------------");
            System.out.print("Enter Your Choice: ");
            
            
           
            int choice= scanner.nextInt();
            
            switch(choice){
                case 1:
                    BookRoom(scanner);
                    break;
                case 2: 
                    CancelBooking(scanner);
                    break;
                case 3:
                    ViewBooking(scanner);
                    break;
                case 4: 
                    exit= true;
                    break; 
                default:
                    System.out.println("Invalid Choice!!!");
            }
        }

    }

M✨, [6/1/2025 9:04 PM]
// Customer Menu
    
    
    public static void BookRoom(Scanner scanner){
        System.out.println("Enter Your Name: ");
        scanner.nextLine();
        String name= scanner.nextLine();
        
        System.out.println("Enter Your Fayda No: ");
        int fayda= scanner.nextInt();
        
        System.out.println("Enter Your Phone No: ");
        int phone = scanner.nextInt();
        
        scanner.nextLine();
        System.out.println("Enter Your Address: ");
        String address= scanner.nextLine();
        
        
        Guest guest = new Guest(fayda,name, phone, address);
        
    
        System.out.println("Select Room Type:");
        System.out.println("1. Single Room");
        System.out.println("2. Double Room");
        System.out.println("3. Suite Room");
        System.out.print("Enter your choice : ");
        int choice = scanner.nextInt();
        
        System.out.println("Enter Your number of Nights: ");
        int nof = scanner.nextInt();
        
      
        scanner.nextLine(); // consume leftover newline
        String date;
         while (true) {
            System.out.print("Enter your check-in date (yyyy-mm-dd): ");
            date = scanner.nextLine();

            try {
                LocalDate parsedDate = LocalDate.parse(date, DateTimeFormatter.ISO_LOCAL_DATE);
                        //past date
                if (parsedDate.isBefore(LocalDate.now())) {
                System.out.println("Check-in date cannot be in the past.");
                continue;
                }

                break;
            } 
            catch (DateTimeParseException e) {
                System.out.println("Invalid date format. Please enter in yyyy-mm-dd format.");
            }
        }



        Room room = null;
         int roomNumber = RoomManager.getNextRoomNumber();
         switch (choice) {
            case 1:
                room = new SingleRoom(roomNumber, true);
                break;
            case 2:
                room = new DoubleRoom(roomNumber, true);
                break;
            case 3:
                room = new SuiteRoom(roomNumber, true);
                break;
                default:
            System.out.println("Invalid room type.");
            return;
            
    }

    room.setNumber_of_Nights(nof); // This sets number of nights correctly
    RoomManager.addRoom(room);

    Bookings booking = new Bookings(guest, room, date); // Also fix parameter here
    Bookings.addBooking(booking);
    booking.showBookingDetails();
    room.bookingRoom();
    room.Calculate_Total_Price();

}


    public static void CancelBooking(Scanner scanner) {
    System.out.print("Enter your full name to cancel booking: ");
    scanner.nextLine(); 
    String name = scanner.nextLine();
    Bookings.cancelBookingByName(name);
 
    }
    
    
    public static void ViewBooking(Scanner scanner) {
    System.out.print("Enter your full name to view booking: ");
    scanner.nextLine(); 
    String name = scanner.nextLine();
    Bookings.viewBookingByName(name);
}

// Admins side
    public static void AddNewRooms(Scanner scanner) {
    System.out.println("Select Room Type to Add:");
    System.out.println("1. Single Room");
    System.out.println("2. Double Room");
    System.out.println("3. Suite Room");

    int roomTypeChoice = scanner.nextInt();
    scanner.nextLine();

    System.out.print("Enter the number of rooms to add: ");
    scanner.nextLine(); 
    int numberOfRooms = scanner.nextInt();
    scanner.nextLine();

    for (int i = 0; i < numberOfRooms; i++) {
        int roomNumber = RoomManager.getNextRoomNumber();
        Room newRoom;

M✨, [6/1/2025 9:04 PM]
switch (roomTypeChoice) {
            case 1:
                newRoom = new SingleRoom(roomNumber, true);
                break;
            case 2:
                newRoom = new DoubleRoom(roomNumber, true);
                break;
            case 3:
                newRoom = new SuiteRoom(roomNumber, true);
                break;
            default:
                System.out.println("Invalid room type.");
                return;
        }
        
        RoomManager.addRoom(newRoom);
    }

    System.out.println(numberOfRooms + " new rooms added successfully.");
}
    
    public static void ViewAllBookings() {
    if (Bookings.getAllBookings().isEmpty()) {
        System.out.println("No bookings found.");
    } else {
        for (Bookings booking : Bookings.getAllBookings()) {
            System.out.println("=================================");
            booking.showBookingDetails();
        }
    }
}

    public static void UpdateBookingAdmin(Scanner scanner) {
    System.out.print("Enter the guest’s full name to update booking: ");
    scanner.nextLine(); 
    String name = scanner.nextLine();

    Bookings booking = Bookings.findBookingByName(name);

    if (booking != null) {
        System.out.println("Select what you want to update:");
        System.out.println("1. Change Room Type");
        System.out.println("2. Change Check-In Date");

        int updateChoice = scanner.nextInt();
        scanner.nextLine();

        switch (updateChoice) {
            case 1:
                System.out.println("Select New Room Type:");
                System.out.println("1. Single Room");
                System.out.println("2. Double Room");
                System.out.println("3. Suite Room");
                int type = scanner.nextInt();
                scanner.nextLine();

                Room newRoom = null;
                int newRoomNumber = RoomManager.getNextRoomNumber();

                switch (type) {
                    case 1:
                        newRoom = new SingleRoom(newRoomNumber, true);
                        break;
                    case 2:
                        newRoom = new DoubleRoom(newRoomNumber, true);
                        break;
                    case 3:
                        newRoom = new SuiteRoom(newRoomNumber, true);
                        break;
                    default:
                        System.out.println("Invalid room type.");
                        return;
                }

                booking.setRoom(newRoom);
                RoomManager.addRoom(newRoom);
                System.out.println("Room type updated.");
                break;

            case 2:
                System.out.print("Enter new check-in date (yyyy-mm-dd): ");
                String newDate = scanner.nextLine();
                booking.setCheckInDate(newDate);
                System.out.println("Check-in date updated.");
                break;

            default:
                System.out.println("Invalid choice.");
        }
    } else {
        System.out.println("No booking found for " + name);
    }
}
    
    public static void DeleteBookingAdmin(Scanner scanner) {
        System.out.print("Enter guest name to delete booking: ");
        scanner.nextLine(); 
        String name = scanner.nextLine();
        Bookings.deleteBookingByName(name);
}
//Main Menu
    public static void main(String[] args) {
        // TODO code  logic here
        
        Scanner scanner = new Scanner(System.in);
        boolean exit = false;

M✨, [6/1/2025 9:04 PM]
while(!exit){
        System.out.println("--------------------------------------------");
        System.out.println("            Welcome to Our Hotel!!!!!       ");
        System.out.println("--------------------------------------------");
        System.out.println("1- Customer Menu");
        System.out.println("2- Admin Menu ");
        System.out.println("3- Exit");
      
        System.out.print("Enter your choice: ");
        int choice = scanner.nextInt();
        scanner.nextLine();
        
        switch (choice) {
            case 1:
                CustomerMenu(scanner);
                break;
            case 2:
                AdminMenu(scanner);
                break;
            case 3: 
                exit=true;
                System.out.println("Thank you for using the Hotel Reservation System!");
                break;
            default:
                System.out.println("Invalid Choice!!!!!");
                break;
            }
        }
    
      scanner.close();
    }
    
}
