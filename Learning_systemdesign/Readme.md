"""✅ Zoho-Style LLD Question — Parking Lot System

Question:
Design a Parking Lot System for a multi-level parking facility. The system should support the following requirements:

Functional Requirements

The parking lot has multiple floors, and each floor has multiple parking spots.

There are three types of vehicles:

Two-wheelers

Cars/SUVs

Heavy vehicles

Each spot can support only certain vehicle types.

When a vehicle enters:

The system should automatically allocate the nearest available spot for that vehicle type.

A parking ticket must be generated with:

Entry time

Vehicle number

Allocated floor & slot number

When a vehicle exits:

Calculate parking fees based on duration.

Free the allocated spot.

System should support:

Query: “How many spots are free for each vehicle type?”

Query: “Show free spots floor-wise.”

Constraints

Parking lot can have up to N floors, each with M spots.

Allocation should be efficient (minimize time to find a free slot).

Multiple vehicles may enter at the same time → design for concurrency or efficient availability tracking.

Expected from Candidate

Class diagram / relationships.

Important classes:

ParkingLot

Floor

ParkingSpot

Vehicle (with subclasses)

Ticket

Payment / FeeStrategy

Algorithms for:

Slot allocation

Pricing calculation

How to handle:

Concurrency

Scalability

Extensions (if interviewer asks):

EV Charging spots

Reservations

VIP parking

Real-time spot availability dashboard