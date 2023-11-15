export default function ondas() {
  return (
    <button
      className="bg-gray-600 border-4 border-black rounded-lg p-5 text-white inline-block font-bold text-2xl text-center cursor-pointer transition ease-in-out delay-150 duration-300"
      style={{
        boxShadow: "8px 8px 0px 0px #000000",
        ':hover': {
          backgroundColor: '#4a5568', // Replace with your hover color
          transform: 'translateY(1px)', // Adjust the amount of translation
        }
      }}
    >
      Click
    </button>
  );
}
