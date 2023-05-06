import './loading-spinner.scss';

function LoadingSpinner() {
  return (
    <div className='parent'>
      <div className='lds-hourglass'></div>
    </div>
  );
}

export default LoadingSpinner;
